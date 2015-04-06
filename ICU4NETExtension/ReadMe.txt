ICU4NET NuGet package has been installed. However YOU ARE NOT DONE YET! Please read on...

To be able to use ICU4NET, you need to take these additional steps:

1. Download ICU4C DLLs from http://download.icu-project.org/files/icu4c/55.1/icu4c-55_1-Win32-msvc10.zip.
2. Extract the "icu4c-55_1-Win32-msvc10.zip/icu/bin" folder into "($SolutionDir)/ICU4C".
3. Add DLLs to the project, but make sure to "Add As Link" (https://msdn.microsoft.com/en-us/library/windows/apps/jj714082(v=vs.105).aspx). It is important that you add those DLLs to the root of the project, i.e. - "($ProjectDir)".
4. For each of the DLLs set "Build Action" to "Content" and "Copy to Output Directory" to "Copy Always".