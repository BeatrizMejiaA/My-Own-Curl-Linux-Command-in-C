# my_curl

#### Description:

###### This is a partial replica of the Unix curl command, 
###### my_curl is used to get data from a server, using HTTP.

###### The purpose of this project was to explore network communication, 
###### the HTTP protocol and the direct use of network sockets. For this reason, 
###### my_curl only supports the HTTP protocol, and none of the numerous curl options: 
###### (-i, -I, -v, -s, etc.) are implemented and my_curl does not support transfer encoding.

#### How to compile:

###### To compile the application, run the next commands.
###### > cd my_CURL
###### > make

#### Running the command:

###### After the command has compiled, run the following command : ./my_curl <URL>

###### example:

###### >./my_curl http://www.columbia.edu/~fdc/sample.html
###### >./my_curl http://www.testingmcafeesites.com/index.html
###### >./my_curl http://www.testingmcafeesites.com/testcat_an.html
###### >./my_curl http://www.testingmcafeesites.com/testcat_ed.html
###### >./my_curl http://www.testingmcafeesites.com/testcat_hr.html
###### >./my_curl http://www.testingmcafeesites.com/testcat_ph.html

###### When finished you can clean the Makefile
###### - make clean to clean the objects
###### - make fclean to clean the objects and the run file ./my_curl
###### - make re to make clean and make fclean
