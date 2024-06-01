# Description
This branch use CMakeLists.txt to create object files only for final program, no shared library 

# cmake useful command
-[1] create the Makefile(and all the belonging directory): `cmake -B build`  
-[2] create executable binary: `cmake --build build`  
(use \`cmake -B build \` to insert inline code "cmake -B build")
# the same command in Bash linux: `sort test.txt`
to check the correctness of self-made software "zf_sort" as a command

# usefull git command
## delete a directory
-[] commit the deleted directory: `git rm -r build`  
-[] commit the changes: `git commit -m "messages"`   
-[] push directly: `git push`
## rename a diretory
-[] `git mv old_name new_name`  
-[] `git commit -m "message"`  
-[] `git push`