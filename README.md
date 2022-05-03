# Function Call DLL Template

Basic template for injecting into applications, define a function with a location. Call with other parameters.

Used a particular popular MOBA game for this demo, which will remain un-named for the longevity of my github account.


![image](https://user-images.githubusercontent.com/84855585/166400730-5ff74ca5-2acb-47de-b251-88959ad89c20.png)


# Finding calling conventions of target function

Using a debugger and comparing with [MSDN's Calling Convention page](https://docs.microsoft.com/en-us/cpp/cpp/argument-passing-and-naming-conventions?view=msvc-170) can work but IDA's decompiler makes this job very easy.

- Find the address of your target function. (For me this was found at (BaseAddress + 0x599D90))
- Find the function in IDA (rebasing to 0x0 is helpful)
- Decompile the function (F5)

Calling convention with arguments in seconds :D
![image](https://user-images.githubusercontent.com/84855585/166401057-584498ca-94cb-4325-8889-8a1186f0e19e.png)


