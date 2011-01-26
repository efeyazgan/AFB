include Makefile.arch
#----------------------------------------------------------------------------------
#TESTS           := afb_analyzer.C
TESTS           := Unfold.C
#TESTS           := afb_analyzer_unfolder.C 
TESTO           := $(TESTS:.C=.o)
#TEST            := afb_analyzer
TEST            := Unfold
#TEST            := afb_analyzer_unfolder

OBJ             = $(TESTO)
PROGRAMS        = $(TEST)

CXXFLAGS      += 
CXXFLAGS      += 
GLIBS         += 
#----------------------------------------------------------------------------------
.SUFFIXES: .$(SrcSuf) .$(ObjSuf) .$(DllSuf)

all:            $(PROGRAMS)

$(TEST):        $(TESTO)
		$(LD) $(LDFLAGS) $^ $(GLIBS) $(OutPutOpt)$@
		@echo "$@ done"

clean:
		@rm -f $(OBJ) $(TESTO) core *~ src/*~ include/*~

.$(SrcSuf).$(ObjSuf):
		$(CXX) $(CXXFLAGS) -c $< -o $@
