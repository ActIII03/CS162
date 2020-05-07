PROJECT = research_draft
TEX=pdflatex
BIBTEX=biber
BUILDTEX= $(TEX) $(PROJECT).tex
PDFVIEWER = evince

#TEX_FILES = $(shell find . -name '*.tex' -or -name '*.sty' -or -name '*.cls')
#BIB_FILES = $(shell find . -name '*.bib')
#BST_FILES = $(shell find . -name '*.bst')
#IMG_FILES = $(shell find . -path '*.jpg' -or -path '*.png' -or \( \! -path './obj/*.pdf' -path '*.pdf' \) )

all:
	$(BUILDTEX)
	$(BIBTEX) $(PROJECT)
	$(BUILDTEX)
	$(BUILDTEX)

clean-all:
	 rm -f *.bcf *.xml *.dvi *.log *.bak *.aux *.bbl *.blg *.idx *.ps *.eps *.pdf *.toc *.out 

clean:
	rm -rf obj/ *bcf *xml *.bbl *.blg *.aux *.ttt *.log *.out *.fff

#TEXINPUTS = .:obj/
#TEXMFOUTPUT = obj/
#
#default: obj/$(PROJECT).pdf
#
#display: default
#	(${PDFVIEWER} $(PROJECT).pdf )
#
#obj/:
#	mkdir -p obj/
#
#obj/$(PROJECT).aux: $(TEX_FILES) $(IMG_FILES) | obj/
#	pdflatex $(PROJECT)
#
#obj/$(PROJECT).bbl: $(BIB_FILES) | obj/$(PROJECT).aux
#	biber obj/$(BIB_FILES)
#	pdflatex  $(PROJECT)
#	
#obj/$(PROJECT).pdf: obj/$(PROJECT).aux $(if $(BIB_FILES), obj/$(PROJECT).bbl)
#	pdflatex $(PROJECT)
