/*
*****************************************************************************

  File        : main.cpp

  The MIT License (MIT)
  Copyright (c) 2018 STMicroelectronics

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

*****************************************************************************
*/

#include <stdio.h>
#include <time.h>
#include "solutions_0.h"

typedef int (*functionTypeAdd)(int a, int b);

void evaluateSolution(functionTypeAdd fun, char* name)
{
    printf("======================================\n");
    printf("%s's impressive solution\n", name);
    int passedTests = 0;
    int failedTests = 0;
    int totalTests = 0;
    clock_t start, end;
    clock_t totalTime = 0;

    for(int a=-2000;a<2000;a++)
    {
        for(int b=-2000;b<2000;b++)
        {
            start = clock();
            int result = fun(a, b);
            end = clock();
            totalTime += (end-start);
            totalTests++;
            if(result == a+b)
            {
                passedTests++;
            }
            else
            {
                failedTests++;
            }
        }
    }
    printf("%d / %d tests passed, %d / %d tests failed\n", passedTests, totalTests, failedTests, totalTests);
    double timeInSec = ((double) totalTime) / CLOCKS_PER_SEC;
    printf("Runtime: %f seconds\n", timeInSec);
    printf("======================================\n");
}

int main(void)
{
    evaluateSolution(frankComputePlus, "Frank");
    evaluateSolution(manuelComputePlus, "Manuel");
    evaluateSolution(robertComputePlus, "Robert");
    evaluateSolution(jensComputePlus, "Jens");
    evaluateSolution(niklasComputePlus, "Niklas");
//    evaluateSolution(niklasComputePlusPrintF, "Print(Niklas)");
    evaluateSolution(stefanComputePlus, "Stefan");
    evaluateSolution(benjaminComputePlus, "Benjamin");
	return 0;
}
