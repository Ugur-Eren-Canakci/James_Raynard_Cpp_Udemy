##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Assignment_9
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :="C:/Users/ugur_/Desktop/Self Studies/Cpp/James_Raynard_Cpp_Udemy/James_Raynard_Cpp_Udemy_Practices"
ProjectPath            :="C:/Users/ugur_/Desktop/Self Studies/Cpp/James_Raynard_Cpp_Udemy/James_Raynard_Cpp_Udemy_Practices/Assignment_9"
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/Assignment_9
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=ugur_
Date                   :=29/12/2024
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/Users/ugur_/Desktop/Self Studies/Cpp/James_Raynard_Cpp_Udemy/James_Raynard_Cpp_Udemy_Practices/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/mingw64/bin/windres.exe
LinkOptions            :=  -static
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/mingw64/bin/ar.exe -r
CXX      := C:/mingw64/bin/g++.exe
CC       := C:/mingw64/bin/gcc.exe
CXXFLAGS :=  -O0 -gdwarf-2 -std=c++17 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/vec_program.cpp$(ObjectSuffix) $(IntermediateDirectory)/deque_program.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/list_program.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/vec_program.cpp$(ObjectSuffix): vec_program.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/ugur_/Desktop/Self Studies/Cpp/James_Raynard_Cpp_Udemy/James_Raynard_Cpp_Udemy_Practices/Assignment_9/vec_program.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/vec_program.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/vec_program.cpp$(PreprocessSuffix): vec_program.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/vec_program.cpp$(PreprocessSuffix) vec_program.cpp

$(IntermediateDirectory)/deque_program.cpp$(ObjectSuffix): deque_program.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/ugur_/Desktop/Self Studies/Cpp/James_Raynard_Cpp_Udemy/James_Raynard_Cpp_Udemy_Practices/Assignment_9/deque_program.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/deque_program.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/deque_program.cpp$(PreprocessSuffix): deque_program.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/deque_program.cpp$(PreprocessSuffix) deque_program.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/ugur_/Desktop/Self Studies/Cpp/James_Raynard_Cpp_Udemy/James_Raynard_Cpp_Udemy_Practices/Assignment_9/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/list_program.cpp$(ObjectSuffix): list_program.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/ugur_/Desktop/Self Studies/Cpp/James_Raynard_Cpp_Udemy/James_Raynard_Cpp_Udemy_Practices/Assignment_9/list_program.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/list_program.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/list_program.cpp$(PreprocessSuffix): list_program.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/list_program.cpp$(PreprocessSuffix) list_program.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


