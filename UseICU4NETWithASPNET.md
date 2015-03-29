# Introduction #

Users are unable to use ICU4NET with ASP.NET Web App. When added references to ICU4NET.dll + ICU4NETExtension.dll, they got the following error:

```

 Server Error in '/' Application.

 The specified module could not be found. (Exception from HRESULT: 0x8007007E)

 Description: An unhandled exception occurred during the execution of the current web request. Please review the stack trace for more information about the error and where it originated in the code. 

 Exception Details: System.IO.FileNotFoundException: The specified module could not be found. (Exception from HRESULT: 0x8007007E)

 Source Error: 

 An unhandled exception was generated during the execution of the current web request. Information regarding the origin and location of the exception can be identified using the exception stack trace below.

 Stack Trace: 

 [FileNotFoundException: The specified module could not be found. (Exception from HRESULT: 0x8007007E)]
   System.Reflection.Assembly._nLoad(AssemblyName fileName, String codeBase, Evidence assemblySecurity, Assembly locationHint, StackCrawlMark& stackMark, Boolean throwOnFileNotFound, Boolean forIntrospection) +0


   System.Reflection.Assembly.nLoad(AssemblyName fileName, String codeBase, Evidence assemblySecurity, Assembly locationHint, StackCrawlMark& stackMark, Boolean throwOnFileNotFound, Boolean forIntrospection) +43
   System.Reflection.Assembly.InternalLoad(AssemblyName assemblyRef, Evidence assemblySecurity, StackCrawlMark& stackMark, Boolean forIntrospection) +127


   System.Reflection.Assembly.InternalLoad(String assemblyString, Evidence assemblySecurity, StackCrawlMark& stackMark, Boolean forIntrospection) +142
   System.Reflection.Assembly.Load(String assemblyString) +28


   System.Web.Configuration.CompilationSection.LoadAssemblyHelper(String assemblyName, Boolean starDirective) +46

[ConfigurationErrorsException: The specified module could not be found. (Exception from HRESULT: 0x8007007E)]


   System.Web.Configuration.CompilationSection.LoadAssemblyHelper(String assemblyName, Boolean starDirective) +613
   System.Web.Configuration.CompilationSection.LoadAllAssembliesFromAppDomainBinDirectory() +203
   System.Web.Configuration.CompilationSection.LoadAssembly(AssemblyInfo ai) +105


   System.Web.Compilation.BuildManager.GetReferencedAssemblies(CompilationSection compConfig) +178
   System.Web.Compilation.BuildProvidersCompiler..ctor(VirtualPath configPath, Boolean supportLocalization, String outputAssemblyName) +54


   System.Web.Compilation.ApplicationBuildProvider.GetGlobalAsaxBuildResult(Boolean isPrecompiledApp) +227
   System.Web.Compilation.BuildManager.CompileGlobalAsax() +52
   System.Web.Compilation.BuildManager.EnsureTopLevelFilesCompiled() +337



 [HttpException (0x80004005): The specified module could not be found. (Exception from HRESULT: 0x8007007E)]
   System.Web.Compilation.BuildManager.ReportTopLevelCompilationException() +58
   System.Web.Compilation.BuildManager.EnsureTopLevelFilesCompiled() +512


   System.Web.Hosting.HostingEnvironment.Initialize(ApplicationManager appManager, IApplicationHost appHost, IConfigMapPathFactory configMapPathFactory, HostingEnvironmentParameters hostingParameters) +729

[HttpException (0x80004005): The specified module could not be found. (Exception from HRESULT: 0x8007007E)]


   System.Web.HttpRuntime.FirstRequestInit(HttpContext context) +8890735
   System.Web.HttpRuntime.EnsureFirstRequestInit(HttpContext context) +85
   System.Web.HttpRuntime.ProcessRequestInternal(HttpWorkerRequest wr) +259

```

# Details #

The error is displayed because one the
managed DLLs in ICU4NET requires native DLLs from ICU project, and ASP.NET runtime
can't resolved its path.

To fix this, add folder which contains ICU's DLLs: **icudt42.dll, icuin42.dll,
icuio42.dll, icule42.dll, iculx42.dll, icutu41.dll, and icuuc42.dll**, to the %PATH%,
and reset Visual Studio + IIS. Another way is to copy these DLLs to the
`C:\Windows\System32\` folder, which is already in the path.

Related thread: http://forums.asp.net/p/939729/1121085.aspx