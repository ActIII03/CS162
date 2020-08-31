PROJECT = term_paper
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
	rm -rf obj/ *.bib *bcf *xml *.bbl *.blg *.aux *.ttt *.log *.out *.fff
