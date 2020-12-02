/**
 * \file
 *
 * \brief   TODO Add a short file description
 *            
 * \details TODO Add additional details.  
 *  
 * \note    TODO Add additional notes.
 * 
 * \author  drayebe               (responsible)
 * \date    02.12.2020               (responsible)
 *
 * \copyright (c) 2020 SICK AG Germany. All rights reserved.
 */
#include <math.h>

int frankComputePlus(int number1, int number2)
{
         return (number1 + number2);
}

int robertComputePlus(int number1, int number2)
{
         return (number1 + number2);
}

int benjaminComputePlus(int number1, int number2)
{
    return (int)(log(exp((double) number1) * exp((double) number2)));
}

int manuelComputePlus(int number1, int number2)
{
    if (number2 == 0)
    {
        return number1;
    }
    else
    {
        return manuelComputePlus( (number1 ^ number2), (number1 & number2) << 1 );
    }
}

int
addABit (int num1, int num2, int a, int temp, unsigned int mask)
{
  //count the number of high bits by shifting: 0,1, 2 or 3 (--> 1,2,4,8)
  int CountOnes = 0x1;
  CountOnes = CountOnes << (((num1 & mask) > 0) ? 1 : 0);
  CountOnes = CountOnes << (((num2 & mask) > 0) ? 1 : 0);
  CountOnes = CountOnes << a;

  //skip if only 0 bits = 1
  //1 high bit: add a bit
  if (CountOnes == 1) //0 x high
    {
      a = 0;
    }
  if (CountOnes == 2) //1 x high
    {
      temp = temp | mask;
      a = 0;
    }
  //2 high bits: add a bit but shifted by 1 (C<bertrag)
  else if (CountOnes == 4)//2 x high
    {
      a = 1;
    }
  //3 high bits: add a bit but shifted by 1 (C<bertrag) + add a bit
  else if (CountOnes == 8)//3 x high
    {
      temp = temp | mask;
      a = 1;
    }


  //find a way to stop in near future :-)
  if (mask & 0x80000000)
    {
      return temp;
    }
  else              //or continue with more bits
    {

      return addABit (num1, num2, a, temp, mask << 1);
    }
}

int jensComputePlus (int number1, int number2)
{
  return addABit (number1, number2, 0, 0, 0x0001);
}

int niklasComputePlus(const int number1, const int number2)
{
    int sum = 0;
    int carry = 0;
    int retVal = 0;

    if (number2 == 0)
    {
        retVal = number1;
    }
    else
    {
        sum = number1 ^ number2;
        carry = (number1 & number2) << 1;
        retVal = niklasComputePlus(sum, carry); // Who needs loops?
    }

    return retVal;
}

int niklasComputePlusPrintF(const int number1, const int number2)
{
    int sum = printf("%*c%*c", number1, ' ', number2, ' ');
    return sum;
}

int stefanComputePlus(int number1, int number2)
{
    if(number2 == 0) // Abbruch Rekursion
    {
        return number1;
    }
    else
    {
        int sum;
        int carry;
        sum   = number1 ^ number2;
        carry = (number1 & number2) << 1;
        return stefanComputePlus(sum,carry);
    }
}
// *****************************************************************************
// Configuration Options:
// *****************************************************************************
// TODO Describe all possible configuration options here.

// *****************************************************************************
// Private definitions:
// *****************************************************************************

// *****************************************************************************
// Private types:
// *****************************************************************************

// *****************************************************************************
// Private function declarations:
// *****************************************************************************

// *****************************************************************************
// Private variables:
// *****************************************************************************

// *****************************************************************************
// Public function definitions:
// *****************************************************************************

// *****************************************************************************
// Private function definitions:
// *****************************************************************************


#ifdef UNITTEST

// *****************************************************************************
// Unittests:
// *****************************************************************************

/**
 * \brief TODO add description
 */
static void testCase001(void);

static void testCase001(void)
{
    // TODO implement test, see Unity documentation for assert definitions!
    //TEST_ASSERT(false);
}


extern uint32_t MODULE_runTests(void) // TODO change name
{
    UNITY_BEGIN();
    RUN_TEST(testCase001);
    return UNITY_END();
}

#endif // UNITTEST




