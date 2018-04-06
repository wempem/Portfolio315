#include <cxxtest/TestSuite.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <time.h>
#include "map.hpp"
#include "ans1.hpp"

class MyTestSuite1 : public CxxTest::TestSuite {
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
            FILE *out = fopen("data/build-times.data", "wr");
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

            int sum = 0;
            int offset = 50;
            for (int offset = 5000; offset >= 8; offset = (int)(offset*.80)) {
                clock_t start = clock(), diff;
                for (int i = 0; i < first.size(); i++) {
                    for (int j = 0; j < last.size(); j+= offset) {
                        sprintf(line, "%s %s", first[i].c_str(), last[j].c_str());
                        map.add(line, i*last.size() + j +1);
                        //printf("%s %d\n", line, i*last.size() + j +1);
                        sum++;
                    }
                }
                diff = clock() - start;

                printf("List with %d items was built in %f seconds\n", sum, (diff*1.0)/CLOCKS_PER_SEC);
                fprintf(out, "%d %f\n", sum, (diff*1.0)/CLOCKS_PER_SEC);
                fflush(out);
            }

            fclose(out);

        }
};

