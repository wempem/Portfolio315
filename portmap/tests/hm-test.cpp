#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <time.h>
#include "map.hpp"
#include "ans1.hpp"

#define SMALL_OFFSET (1000)
#define MEDIUM_OFFSET (250)
#define LARGE_OFFSET (50)

// Runs the overall tests for a certain build_offset
void run_hm_test(std::vector<std::string> &first, std::vector<std::string> &last, const char *name, const int build_offset);

// Runs an individual test for s specific range (specified by ilen & jlen).
int run_hm(Map &map, const int ilen, const int jlen);

class MyTestSuite1 : public CxxTest::TestSuite {
    //const char[][] answers = {"test"};
        Map map;
    public:
        void validate(int len) {
            clock_t start = clock(), diff;
            int id;
            for (int i = 0; i < len; i++) {
                map.get(answers[i], id);
                TS_ASSERT(ids[i] == id);
            }
            diff = clock() - start;
            printf("Validated in %f seconds\n", (diff*1.0)/CLOCKS_PER_SEC);
        }
        void test1(void) {
            // Longest fname + lastname = 27.
            FILE *fnames = fopen("firstnames.txt", "r");
            FILE *lnames = fopen("lastnames.txt", "r");
            std::vector<std::string> first;
            std::vector<std::string> last;
            char line[1024];

            while(fgets(line, 1024, fnames) != NULL) {
                line[strlen(line)-1] = '\0';
                first.push_back(line);
            }

            printf("\n");

            while(fgets(line, 1024, lnames) != NULL) {
                line[strlen(line)-1] = '\0';
                line[strlen(line)-1] = '\0';
                last.push_back(line);
            }

            fclose(fnames);
            fclose(lnames);

            printf("Number of first names:%d\n", first.size());
            printf("Number of last names:%d\n", last.size());

            run_hm_test(first, last, "Small", SMALL_OFFSET);
            run_hm_test(first, last, "Medium", MEDIUM_OFFSET);
            run_hm_test(first, last, "Large", LARGE_OFFSET);

            /*
            printf("'a' = %d\n", map.howMany("a"));
            printf("'b' = %d\n", map.howMany("b"));
            printf("'c' = %d\n", map.howMany("c"));
            printf("'d' = %d\n", map.howMany("d"));
            printf("'e' = %d\n", map.howMany("e"));
            printf("'f' = %d\n", map.howMany("f"));
            printf("'g' = %d\n", map.howMany("g"));
            printf("'h' = %d\n", map.howMany("h"));
            printf("'i' = %d\n", map.howMany("i"));
            printf("'j' = %d\n", map.howMany("j"));
            printf("'k' = %d\n", map.howMany("k"));
            printf("'l' = %d\n", map.howMany("l"));
            printf("'m' = %d\n", map.howMany("m"));
            printf("'n' = %d\n", map.howMany("n"));
            printf("'o' = %d\n", map.howMany("o"));
            printf("'p' = %d\n", map.howMany("p"));
            printf("'q' = %d\n", map.howMany("q"));
            printf("'r' = %d\n", map.howMany("r"));
            printf("'s' = %d\n", map.howMany("s"));
            printf("'t' = %d\n", map.howMany("t"));
            printf("'u' = %d\n", map.howMany("u"));
            printf("'v' = %d\n", map.howMany("v"));
            printf("'w' = %d\n", map.howMany("w"));
            printf("'x' = %d\n", map.howMany("x"));
            printf("'y' = %d\n", map.howMany("y"));
            printf("'z' = %d\n", map.howMany("z"));
            printf("'' = %d\n", map.howMany(""));
            */
            printf("Test done...\n");
        }
};


void run_hm_test(std::vector<std::string> &first, std::vector<std::string> &last, const char *name, const int build_offset) {
    std::vector<std::string> SNAMES;
    std::vector<int> SIDS;
    int sum = 0;
    char line[1024];
    Map map;
    char buff[1024];
    FILE *out;
    float fdiff;

    sprintf(buff, "data/hm-%s-times.data", name);
    out = fopen(buff, "wr");

    printf("Building %s data set\n", name);
    clock_t start = clock(), diff;
    for (int i = 0; i < first.size(); i++) {
        for (int j = 0; j < last.size(); j+= build_offset) {
            sprintf(line, "%s %s", first[i].c_str(), last[j].c_str());
            map.add(line, i*last.size() + j +1);
            SNAMES.push_back(line);
            SIDS.push_back(i*last.size() + j +1);
            sum++;
        }
    }
    diff = clock() - start;

    printf("List with %d items was built in %f seconds\n", sum, (diff*1.0)/CLOCKS_PER_SEC);

    int hmsum = 0;
    for (int i = 1; i <= 26; i++) {
        start = clock();
        hmsum = run_hm(map, i, i);
        diff = clock() - start;
        fdiff = 1.0 * diff;
        fdiff /= CLOCKS_PER_SEC;

        fprintf(out, "%d %f\n",
                i,
                fdiff);
        fflush(out);

        printf("howMany, with i = %d, ran in %f seconds\n", i, (diff*1.0)/CLOCKS_PER_SEC);
    }

    // Make sure we found them
    TS_ASSERT(hmsum == sum);

    fclose(out);
}

int run_hm(Map &map, const int ilen, const int jlen) {
    int hmsum = 0;
    char buff[1024];

    for (int i = 0; i < ilen; i++) {
        buff[0] = 'A' + i;
        for (int j = 0; j < jlen; j++) {
            buff[1] = 'a' + j;
            buff[2] = '\0';
            hmsum += map.howMany(buff);
        }
    }

    return hmsum;
}
