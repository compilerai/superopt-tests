import os
from colorama import Fore, Back, Style
# this python files runs all the files one by one and prints whether warning was generated or not.
def check_files(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".c"):
                # if it has warn keyword in the filename, then make flag = 0
                flag_warn = 1
                if "warn" in file:
                    flag_warn = 0
                file_path = os.path.join(root, file)
                compile_command = f"clang {file_path} -o {directory}/obj/{file[:-2]}.out > /dev/null 2>&1"
                compile_result = os.system(compile_command)

                print(f"Checking file: {file_path}", end = " ")

                if compile_result != 0:
                    print("Compilation failed, as Error Raised ", end="")
                    if flag_warn == 0:
                        print(Fore.GREEN + "Test " + file + " passed" + Style.RESET_ALL)
                    else:
                        print(Fore.RED + "Test " + file + " failed" + Style.RESET_ALL) 
                else:
                    # we want to study warnings generated during compilation and not runtime
                    command_with_flag = "clang -Werror " + file_path + f" -o {directory}/obj/{file[:-2]}.out > /dev/null 2>&1"
                    with_flag_command_result = os.system(command_with_flag) # 0 means no warning
                    if ((with_flag_command_result == 0) == flag_warn):
                        print(Fore.GREEN + "Test " + file + " passed" + Style.RESET_ALL)
                    else:
                        print(Fore.RED + "Test " + file + " failed" + Style.RESET_ALL)
    os.system(f"rm {directory}/obj/*.out")
# Specify the directory containing the C files
# directory = "/home/bhavesh/desktop/superopt-project/superopt-tests/misra-c-rules"
directory = "."
check_files(directory)
