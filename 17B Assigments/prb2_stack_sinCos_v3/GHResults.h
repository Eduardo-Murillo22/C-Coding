/* File:   GHResults.h
 * Author: DanYell
 * Created on December 12, 2023, 6:37 PM
 */

#ifndef GHRESULTS_H
#define GHRESULTS_H
using namespace std;  //STD Name-space where Library is compiled
struct GHResults {
public:
        float yVal; // y = sinh(radian) or y = cosg(radian)
        int hCount; // sinh() counter
        int gCount;// cosh() counter
};
#endif /* GHRESULTS_H */

