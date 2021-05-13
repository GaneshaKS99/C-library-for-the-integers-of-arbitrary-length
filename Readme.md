Introduction

Q. What is an intal?
A: intal is nothing but integers of arbitrary length. int has a limitation on its length as 2147483647 which is 2 raised to 31. During calculations in our code we may encounter numbers larger than that. for example the factorial of a number may easiy exceed the max value of int. The same is true for Fibonacci numbers also. That is why using some other representation of integers we have to try and implement methods to handle such large value computations. 

Q. How is intal different from integer in general and integer data types supported by C?
A: All the calculations will essentially be the same for both the intal and the all the normal integer data types. But the main difference is in implementation. All the standard operators cannot handle intal. long, signed, unsigned integer operations can be done in almost all compilers and languages but intal offers the problem that the computation is considerably slower and most systems are limited in practice by the total storage available. There are some workarounds for this like storing the numbers in fixed point format or floating point format but even then during division or GCD the numbers can quickly become unwieldy. This is essentially why intal is used and is thus an upgraded version of the integers in C.

Q. What are the applications of intal?
A:  intal is generally used in the following areas
		1. Cryptography: writing more and more secure keys that will be harder to crack without the appropriate key
		2. computing the values of constants like pi, phi and so on to more and more degrees of accuracy.
		3. for developing programming languages with more attention to precision during any type of calculations.
	The general idea is that intal can be used whenever we need more precision in any sort of computations.


Approach

1. intal_add : This implementation is done simply by adding numbers digit by digit and then taking care of the carry in another loop if the number is very large. Since this the integers are in string format i have written a small function called push which places the digit accordingly and a "\0" at the end. intal_add is used many times later in the code.

2. intal_diff : The diff function needs to be implemented a little more carefully since negative answers may appear. So at the beginning we use intal_compare which is a function implemented to compare the two intals. If the answer may be negative( which can be figured out using intal_compare) then we rearrange the intals. After reversing each string we then proceed to subtract them digit by digit and then handing the carry wherever needed. The final answer is then reversed to get the difference between the two intals. The reversing of the string is done by another small function that I have written called the string_reverse function. 

3.intal_compare : This is a direct implementation. After removing the useless zeroes( also done in all the remaining functions) we proceed to compare them digit by digit and compute the length of each intal. then it is a simple matter of comparing these two lengths and returning the appropriate result.

4.intal_multiply : After making sure that none of the two intals are NULL we proceed to comparison of lengths and allocate it to appropriate strings. We create a third intal whose length will be the sum of the lengths of the two intals. this is to make sure that the product does not exceed the range of the variable that it is assigned to. Then we carefully calculate the product of the digits within set limits and take care of the carry each time. After computing the product we add the carry and repeat this process till we have the desired result.

5. intal_mod : This can be implemented by using intal_add, intal_diff, intal_compare and intal_multiply together. A helper function is required to find the divisor of the two intals and this will be used while comparing the two intals in the mod function. The variables must freed after use for each of the functions. So after all this the mod will be returned. 

6. intal_pow : To calculate this we use the intal_multiply function that we have implemented above by running it in a loop. There is a helper function called tostring which converts the integers that arrive as parameters to a string because intal_multiply handles intals as input and not integers. The final value is returned once the loop is finished after taking care of the necessary cases.

7.intal_gcd : Using intal_mod we can implement gcd by calling intal_mod for the two given intals and then doing some basic operations on the two strings like intal_compare and strcpy. This implementation becomes easy since intal_mod is already done and is crucial to this.

8.intal_fibonacci : The implementation of this becomes easier since we have the function that does addition i.e., intal_add. using this we run a loop upto the given limit and keep adding the numbers everytime. After the loop stops we have our Fibonacci number that is then returned.

9.intal_factorial : The implementation of this becomes easier since we have the function that does multiplication i.e., intal_multiply. using this we run a loop upto the given limit and keep multiplying the numbers everytime. After the loop stops we have the Factorial of our number that is then returned.

10.intal_bincoeff : binomial coefficient can be implemented two separated loops. we calculate the sum upto half using two nested loops and run the loops again to compute the next half from k to n. Thus we get the (nCk) value which is then returned using a temporary variable

11. intal_max: This is done using intal_compare function. we need to go through all the values in the string in a loop and run the compare function everytime.The compare function will return a +1 value whenever the next string is greater than the current maximum. We return the value of the index of the first max variable at the end.

12. intal_min: This is done using intal_compare function. We need to go through all the values in the string in a loop and run the compare function everytime.The compare function will return a -1 value whenever the next string is less than the current minimum. We return the value of the index of the first min variable at the end.

13. intal_search: This is done using intal_compare function. We need to go through all the values in the string in a loop and run the compare function everytime.The compare function will return 0 value when the string is matched. We return the value of the index of key at the end.

14.intal_sort : Since the implementation of the sort is specified to be within O(nlogn) time we can use either the standard implementation of the merge sort or the heap sort. I have implemented heap sort. The maib areas where we have to take care is the places where we swap the values. we can use strcpy() function under the string.h library. This swapping is done in the helper function heapify() which is necessary for the implementation. This heapify is called in a loop i.e., the standard heapsort algorithm.


15.intal_binsearch : The implementation of this follows the standard binary search implementation for integer values. The main difference is that whenever we need to compare the key and the current value we need to use the intal_compare function instead of directly using the comparison operators since the values are in string format which can be handled through intal_compare.


16. intal_coin_row: The Dynamic implementation of the coin row algorithm can be implemented very easily to handle the intal cases too. The main changes would be the places where we add the money every time. In this case we can use the intal_add function everytime and then return the max cost at the end.

Additional helper functions used are intal_decrement( helper for intal_power ), intal_create( creates the intal after formatting it correctly), intal_destroy( frees the intal pointer). All pointers where freed whenever possible.

Future Work

Q. Further functionalities that can be added?
A: Several key functionalites can be added like division, all the types of sorting algorithms, all the types of searching algorithms, conversion from one datatype to another and finally algorithms to handle some bitwise operations can be done too.

Q. If no restrictions how would you implement a library to handle intal?
A: If no restrictions were offered the built in libraries could be used more frequently. In this implementation we had to do everything from scratch. There are several functionalities already avalaible in C which can be used more. Also would look into other languages like python were string operations can be easily done.

