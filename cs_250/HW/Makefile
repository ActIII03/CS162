PROJECT = HW5

default: obj/$(PROJECT).pdf

display: default
	(${PDFVIEWER} $(PROJECT).pdf )

TEXINPUTS = .:obj/
TEXMFOUTPUT = obj/

TEX_FILES = $(shell find . -name '*.tex' -or -name '*.sty' -or -name '*.cls')
BIB_FILES = $(shell find . -name '*.bib')
BST_FILES = $(shell find . -name '*.bst')
IMG_FILES = $(shell find . -path '*.jpg' -or -path '*.png' -or \( \! -path './obj/*.pdf' -path '*.pdf' \) )

PDFVIEWER = evince

clean:
	rm -rf obj/ *.aux *.log *.out

obj/:
	mkdir -p obj/

obj/$(PROJECT).aux: $(TEX_FILES) $(IMG_FILES) | obj/
	pdflatex $(PDFLATEX_FLAGS) $(PROJECT)

obj/$(PROJECT).bbl: $(BIB_FILES) | obj/$(PROJECT).aux
	bibtex obj/$(PROJECT)
	pdflatex $(PDFLATEX_FLAGS) $(PROJECT)
	
obj/$(PROJECT).pdf: obj/$(PROJECT).aux $(if $(BIB_FILES), obj/$(PROJECT).bbl)
	pdflatex $(PDFLATEX_FLAGS) $(PROJECT)
