##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ipass
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\robbie\Downloads\c_codelite_workspace_v2\c_workspace"
ProjectPath            := "C:\Users\robbie\Downloads\c_codelite_workspace_v2\c_workspace\ipass"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=robbie
Date                   :=01/06/2016
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-lGdi32.lib
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="ipass.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/engine.cpp$(ObjectSuffix) $(IntermediateDirectory)/joystick.cpp$(ObjectSuffix) $(IntermediateDirectory)/servo.cpp$(ObjectSuffix) $(IntermediateDirectory)/stepmotor.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/robbie/Downloads/c_codelite_workspace_v2/c_workspace/ipass/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/engine.cpp$(ObjectSuffix): engine.cpp $(IntermediateDirectory)/engine.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/robbie/Downloads/c_codelite_workspace_v2/c_workspace/ipass/engine.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/engine.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/engine.cpp$(DependSuffix): engine.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/engine.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/engine.cpp$(DependSuffix) -MM "engine.cpp"

$(IntermediateDirectory)/engine.cpp$(PreprocessSuffix): engine.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/engine.cpp$(PreprocessSuffix) "engine.cpp"

$(IntermediateDirectory)/joystick.cpp$(ObjectSuffix): joystick.cpp $(IntermediateDirectory)/joystick.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/robbie/Downloads/c_codelite_workspace_v2/c_workspace/ipass/joystick.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/joystick.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/joystick.cpp$(DependSuffix): joystick.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/joystick.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/joystick.cpp$(DependSuffix) -MM "joystick.cpp"

$(IntermediateDirectory)/joystick.cpp$(PreprocessSuffix): joystick.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/joystick.cpp$(PreprocessSuffix) "joystick.cpp"

$(IntermediateDirectory)/servo.cpp$(ObjectSuffix): servo.cpp $(IntermediateDirectory)/servo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/robbie/Downloads/c_codelite_workspace_v2/c_workspace/ipass/servo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/servo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/servo.cpp$(DependSuffix): servo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/servo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/servo.cpp$(DependSuffix) -MM "servo.cpp"

$(IntermediateDirectory)/servo.cpp$(PreprocessSuffix): servo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/servo.cpp$(PreprocessSuffix) "servo.cpp"

$(IntermediateDirectory)/stepmotor.cpp$(ObjectSuffix): stepmotor.cpp $(IntermediateDirectory)/stepmotor.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/robbie/Downloads/c_codelite_workspace_v2/c_workspace/ipass/stepmotor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stepmotor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stepmotor.cpp$(DependSuffix): stepmotor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stepmotor.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/stepmotor.cpp$(DependSuffix) -MM "stepmotor.cpp"

$(IntermediateDirectory)/stepmotor.cpp$(PreprocessSuffix): stepmotor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stepmotor.cpp$(PreprocessSuffix) "stepmotor.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


