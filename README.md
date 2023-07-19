# Engineering-Entrance-Mock-Test-
Introduction			
	We observe that, Nowadays world is becoming more & more competitive & wide. To survive in this modern world, we should keep ourselves updated with knowledge of the all things.
  	Today the focus is given more on developing general knowledge & also it is seen that our young generations is more interested in competitive exam. It is not possible to read all the theory contents in the books & by reading books we can’t remember 100% knowledge from that. Any exam preparation is incomplete without practicing the topics you are studying. For getting the best results, you need to test your preparation. Practicing mock tests provides a better perspective of what kind of questions will appear in the exam. They also help in improving the score in competitive exams.
The main objective of this Mock Test application  is to reduce the paper work and make it in the digital mode, gives good practice ,gives a feeling of actual exam.

Problem Statement
	Mock tests are replicated tests based on the annual or competitive exam’s pattern. The main objective behind creating online Mock test series is to judge the potential of students before writing the actual exam. 
	The problem statement is to create Mock test application for MHT CET students. 
	Any exam preparation is incomplete without practicing the topics you are studying.  It is not possible to read all the theory contents in the books & by reading books we can’t remember 100% knowledge from that. This is the big disadvantage while preparing for exam.
	The main objective of this Mock Test application  is to reduce the paper work and make it in the digital mode, gives good practice ,gives a feeling of actual exam.
	Advantages are given below:
1.	Practice Makes Man Perfect
2.	Time Management
3.	Sheds Off that Extra Pressure
4.	Introduces You to The Paper Pattern
5.	Another Revision

Algorithm
1.Start.
2. Ask the user for choice
	1.registration,2.login
3. Enter the username and password. 
4.  If(Username and password correct )
	Print successfully login.
      Else
	Print username and password is wrong
5. Start Mock Test.
6. Enter your group.
7. Display question with option
	If(correct answer)
		Print correct answer
	Else 
		Print wrong answer
8. If the ans is correct 
	Score++ (increment score)
9.  Display  the final result.
10. End . 

Solution Techniques
Data Structures / Explanation of Algorithm Used

	For this mock test application ,we used  c programming language.
	Also we used array in this program.
	We used function call in this program ,because we provide lot of option to the user and when user select one option ,program directly call that function.
	Also we used file handling ,for storing the data, data means questions and options that program will display to the user. For reading this file we using string function.
	We used time.h header file.

System Requirements

Hardware Requirement

	Processor :  AMD Ryzen 5 4600H 
	Ram  :  8.00 GB

Software Requirements

	Programming language: C
	Compiler: GNU GCC compiler.

Implementation Details
System defined functions

1.fopen()
The C library function FILE *fopen(const char *filename, const char *mode) opens the filename pointed to, by filename using the given mode.
Declaration
Following is the declaration for fopen() function.
FILE *fopen(const char *filename, const char *mode)

2.fclose()
The C library function int fclose(FILE *stream) closes the stream. All buffers are flushed.
Declaration
Following is the declaration for fclose() function.
int fclose(FILE *stream

3.fgets()
The C library function char *fgets(char *str, int n, FILE *stream) reads a line from the specified stream and stores it into the string pointed to by str. It stops when either (n-1) characters are read, the newline character is read, or the end-of-file is reached, whichever comes first.
Declaration
Following is the declaration for fgets() function.
char *fgets(char *str, int n, FILE *stream)

4.fread()
The C library function size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) reads data from the given stream into the array pointed to, by ptr.
Declaration
Following is the declaration for fread() function.
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)

5.fwrite()

The C library function size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) writes data from the array pointed to, by ptr to the given stream.
Declaration
Following is the declaration for fwrite() function.
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)

5.2User defined functions

1.pcm()

In this function ,pcm is used for calling mock test that are based on subject physics ,chemistry ,maths.

2.pcb()

In this function ,pcb is used for calling mock test that are based on subject physics ,chemistry ,biology.

3.mhtcet1()

When user select this function it will display the mock test that are based on physics ,chemistry,maths.

4.mhtcet2()

When user select this function it will display the second  mock test that are based on physics ,chemistry,maths.

5.mhtcet3()

When user select this function it will display the mock test that are based on physics ,chemistry,biology.

6.mhtcet4()

When user select this function it will display the second mock test that are based on physics ,chemistry,maths.
User Manual (Screen Shots and explain each screen shots in 2to 3 lines)

1.here we first ask the user to register if he already register then we provide login option.

2.user can enter his/her name and surname then user enter its username and password.

3.user enter its user  ID  and password if password is correct then program prints successful login ,if password is incorrect ,then it shows wrong password and
Program will exit. Then  user can choose his group (PCM or PCB).

4.then the mock test start.question and option are display sequentially.
5.And finally ,the result will display on screen with score and time taken by user to complete test.
   Then we provide two option ,that are,restart and exit. 

References

Reference book

	C complete reference.
	Let us c 4th edition by Yashwant kanetkar


Web reference
	https://byjusexamprep.com/online-test-series
	https://www.pariksha.co 

**Note  : 
1.	Use Font Size :- Title/Chapter Name (Font size 16, Times New Roman), Subtitle (Font size 14, Times New Roman), Contents/Text (Font size 12, 
2.	Total Project report copies = One hard copy for college [Spiral binding], One hard copy for student [Spiral binding], One hard copy to guide if required. 
3.	Line Spacing 1.5 with justified text alignment
4.	Prepare and submit the CD, which includes PPT, Report  and Code
5.	Insert the mini project name in Header at right corner 
6.	Insert Dept.of CSE, TKIET Warananagar in footer at  left corner and page no  right corner in footer.



