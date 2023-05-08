##
## EPITECH PROJECT, 2023
## RayTracer
## File description:
## Documentation makefile
##


EXTRA_PARAMS_PLANTUML 	= 	plantuml
PLANTUML_PUML			=	uml.puml
PLANTUML_TARGET			=	$(PLANTUML_PUML:%.puml=%.svg)


docs: uml doxygen

clean-doxygen:
	rm -rf docs
	rm -rf latex

doxygen: clean-doxygen
	doxygen ./Doxyfile
	touch ./docs/.nojekyll

clean-uml:
	rm -rf ${PLANTUML_TARGET}
	rm -rf ${PLANTUML_PUML}

uml: SOURCE = $(shell find ../src ../PluginsExt -name "*.hpp" -print)
uml: INC_UML = $(addprefix -i , $(SOURCE))
uml: clean-uml
	hpp2plantuml -d ${INC_UML} -o ${PLANTUML_PUML}
	${EXTRA_PARAMS_PLANTUML} -tsvg ${PLANTUML_PUML}
