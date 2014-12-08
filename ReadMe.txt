Eagle Eye ReadMe

Starting Eagle Eye:

To run the Eagle Eye application ensure that all source code files, including the makefile, are in the same directory.
Enter [make] into the command line without any additional options. This will build and link the appropriate files as necessary.
Then enter [EagleEye] into the command line to begin the application. Once the application begins instructions on how to utilize it 
will be provided by the application.

Note: Any image file that is to be transformed MUST be in the same directory as the source code for the application.

Running Tests:

To run the acceptance tests for the application ensure that all source code files, as well as the provided sample image files,
are in the same directory. Enter [make testDriver] into the command line without any additional options. This will build and link
the appropriate files as necessary to run the tests.Then enter [testDriver] into the command line to begin the test driver. Once the 
test driver begins further instructions on how to operate it will be provided by the test driver.

Note: Some tests will create numerous test images. Enter [make imgclean] into the command line to remove all created test images. 
It is recommended that this be done after each test is run to ensure that the tests do not take up too much space of the user. 