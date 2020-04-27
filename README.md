## mvbuild

A fast and tiny C program which kills a specified process and copies contents of a file to another location. 

Meant to be used as a post-build step when working with DLLs to easily launch an application after a new DLL is compiled.


Command-Line Arguments:

	-class string
		Process class name to kill. e.g., "ConsoleWindowClass"
	-src string
		Source to copy contents from. Must be a full path.
	-dst string
		Destination to copy contents to. Must be a full path.


