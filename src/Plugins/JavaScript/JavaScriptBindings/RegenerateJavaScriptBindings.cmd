setlocal EnableDelayedExpansion

cd..
doxygen JavaScriptBindings\JavaScriptBindings.doxyfile
..\JavaScript\BindingsGenerator\bin\release\BindingsGenerator.exe JavaScriptBindings\JavaScriptDocs\xml JavaScriptBindings . JavaScriptInstance _Entity _IComponent _AttributeChange
