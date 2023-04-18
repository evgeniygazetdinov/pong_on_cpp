
FILE=game;
COMPILE_TEXT="g++ main.cpp -I/usr/local/Cellar/sfml/2.5.1.2/includ/e -o game -L /usr/local/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system";
if [ -f "$FILE" ]; then
    eval "rm -rf $FILE";
    eval $COMPILE_TEXT;                 
    eval "./$FILE";
else 
    eval $COMPILE_TEXT;
    eval "./$FILE";
fi