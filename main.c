#include "libs/data_structures/vector/vectorVoid.h"
#include <malloc.h>
#include <assert.h>
#include <ctype.h>
#include "libs/strings/string/string_.h"
#include <string.h>
#define STATS_HEADER "cpdomains = ["
#define STATS_END "]"
#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)
typedef struct DomainRecord {
    long counter;
    WordDescriptor domain;
} DomainRecord;
typedef struct DomainCounter {
    long counter;
    char domain[255];
} DomainCounter;
int compareDomainCounterNames(const void *domainCounterPtr1, const void *domainCounterPtr2) {
    DomainRecord *domainCounter1 = (DomainRecord *)domainCounterPtr1;
    DomainRecord *domainCounter2 = (DomainRecord *)domainCounterPtr2;
    WordDescriptor word1 = domainCounter1->domain;
    WordDescriptor word2 = domainCounter2->domain;

    unsigned long len1 = word1.end - word1.begin;
    unsigned long len2 = word2.end - word2.begin;
    unsigned long min_len = len1;
    if (min_len > len2) {
        min_len = len2;
    }

    int res = memcmp(word1.begin, word2.begin, min_len);

    if (res == 0) {
        if (len1 != len2) {
            res = len1 > len2 ? 1 : -1;
        }
    }
    return res;
}

void parsedDomainStat(vectorVoid *data, char *start, char *end) {
    int count = 0;
    for (char *i = start; i <= end; ++i) {
        if (isdigit(*i)) {
            count = strtol(i, &start, 10);
            break;
        }
    }
    char *endPtr = end;
    for (char *i = end; i <= start; ++i) {
        if (*i == '"') {
            *endPtr = *i;
            endPtr--;
            continue;
        }
        if ((*i == '.') || (*i == ' ')) {
            WordDescriptor word = {i + 1, endPtr};
            DomainRecord domain = {count, word};
            pushBackV(data, &domain);
        }
        if (*i == ' ') {
            break;
        }
    }

}
vectorVoid ShowStats(char *stats){
    char *idx_start=strstr(stats, STATS_HEADER);
    char *idx_end= strstr(stats,STATS_END);
    if((idx_start==NULL)|| (idx_end==NULL)){
        fprintf(stderr,"Error input data");
            exit(1);
        }
    vectorVoid data= createVectorV(0, sizeof(DomainRecord));
    idx_start+= sizeof(STATS_HEADER);
    idx_end= idx_end- sizeof(STATS_END)+1;
    char *token=idx_start;
    int starttoken=0;
    while (idx_start!=idx_end){
        if(*idx_start!=' '){
            starttoken=1;
        }
        if(*idx_start==','){
            parsedDomainStat(&data,token,idx_start-1);
            starttoken=0;
        }
        idx_start++;
    if (!starttoken) {
        token = idx_start;
    }
}
    parsedDomainStat(&data,token,idx_start-1);
    qsort(data.data,data.size, sizeof(DomainRecord),compareDomainCounterNames);
    vectorVoid group= createVectorV(0, sizeof(DomainCounter));
    DomainRecord domain;
    DomainRecord prev_domain;
    getVectorValueV(&data,0,&prev_domain);
    int sum=prev_domain.counter;
    for (int i = 1; i < data.size+1; ++i) {
        if(i!=data.size){
            getVectorValueV(&data, i, &domain);
            if (compareDomainCounterNames(&prev_domain, &domain) == 0) {
                sum += domain.counter;
                continue;
            }
        }
        DomainCounter domainCounter = {sum};
        copy(prev_domain.domain.begin, prev_domain.domain.end, domainCounter.domain);
        pushBackV(&group, &domainCounter);

        prev_domain = domain;
       sum = prev_domain.counter;
    }

    return group;

}
void test(){
    char *stats="cpdomains = [\"900 google.mail.com\", \"50 yahoo.com\", \"1 intel.mail.com\", \"5 wiki.org\"]\0";
    vectorVoid res = ShowStats(stats);

    DomainCounter expDomains[] = {{951, "com"}, {900, "google.mail.com"},
                                  {1, "intel.mail.com"}, {901, "mail.com"},
                                  {5, "org"}, {5, "wiki.org"},
                                  {50, "yahoo.com"}};

    for (int i = 0; i < res.size; i++) {
        DomainCounter domain;
        getVectorValueV(&res, i, &domain);
        assert(expDomains[i].counter == domain.counter);
        ASSERT_STRING(expDomains[i].domain, domain.domain);
    }
}

int main() {
    test();
}