#!/bin/sh

FILE="text.txt"
FILE2="Makefile"
FILE3="expression.txt"
SUCCESS=0
FAIL=0
COMPARE=""
echo "" > fail.txt


echo "dream $FILE"
./s21_grep dream $FILE > my_grep.txt
grep dream $FILE > grep.txt
COMPARE="$(diff -q my_grep.txt grep.txt)"
if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
then
    echo "./s21_grep dream $FILE" >> fail.txt
    ((FAIL++))
else
    ((SUCCESS++))
fi
#rm my_grep.txt grep.txt

echo "dream $FILE $FILE2"
./s21_grep dream $FILE $FILE2> my_grep.txt
grep dream $FILE $FILE2> grep.txt
COMPARE="$(diff -q my_grep.txt grep.txt)"
if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
then
    echo "./s21_grep dream $FILE $FILE2" >> fail.txt
    ((FAIL++))
else
    ((SUCCESS++))
fi
#rm my_grep.txt grep.txt

for FLAG in -i -v -h -s -o -c -l -n -e
do {
    echo "$FLAG dream $FILE"
    ./s21_grep $FLAG dream $FILE > my_grep.txt
    grep $FLAG dream $FILE > grep.txt
    COMPARE="$(diff -q my_grep.txt grep.txt)"
	if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
	then
        echo "./s21_grep $FLAG dream $FILE" >> fail.txt
        ((FAIL++))
	else
		((SUCCESS++))
	fi
    #rm my_grep.txt grep.txt
}
done

for FLAG in -i -v -h -s -o -c -l -n -e
do {
    echo "$FLAG dream $FILE $FILE2"
    ./s21_grep $FLAG dream $FILE $FILE2 > my_grep.txt
    grep $FLAG dream $FILE $FILE2 > grep.txt
    COMPARE="$(diff -q my_grep.txt grep.txt)"
	if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
	then
        echo "./s21_grep $FLAG dream $FILE $FILE2" >> fail.txt
        ((FAIL++))
	else
		((SUCCESS++))
	fi
    #rm my_grep.txt grep.txt
}
done

for FLAG in -i -v -h -s -o -c -l -n
do {
    echo "$FLAG -e 'the world' $FILE"
    ./s21_grep $FLAG -e 'the world' $FILE > my_grep.txt
    grep $FLAG -e 'the world' $FILE > grep.txt
    COMPARE="$(diff -q my_grep.txt grep.txt)"
	if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
	then
        echo "./s21_grep $FLAG -e 'the world' $FILE" >> fail.txt
        ((FAIL++))
	else
		((SUCCESS++))
	fi
    #rm my_grep.txt grep.txt
}
done

for FLAG in -i -v -h -s -o -c -l -n
do {
    echo "$FLAG -e 'the world' $FILE $FILE2"
    ./s21_grep $FLAG -e 'the world' $FILE $FILE2 > my_grep.txt
    grep $FLAG -e 'the world' $FILE $FILE2 > grep.txt
    COMPARE="$(diff -q my_grep.txt grep.txt)"
	if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
	then
        echo "./s21_grep $FLAG -e 'the world' $FILE $FILE2" >> fail.txt
        ((FAIL++))
	else
		((SUCCESS++))
	fi
    #rm my_grep.txt grep.txt
}
done

for FLAG in -i -v -h -s -o -c -l -n
do {
    echo "$FLAG -e 'The World' $FILE"
    ./s21_grep $FLAG -e 'The World' $FILE > my_grep.txt
    grep $FLAG -e 'The World' $FILE > grep.txt
    COMPARE="$(diff -q my_grep.txt grep.txt)"
	if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
	then
        echo "./s21_grep $FLAG -e 'The World' $FILE" >> fail.txt
        ((FAIL++))
	else
		((SUCCESS++))
	fi
    #rm my_grep.txt grep.txt
}
done

for FLAG in -i -v -h -s -o -c -l -n
do {
    echo "$FLAG -e 'The World' $FILE $FILE2"
    ./s21_grep $FLAG -e 'The World' $FILE $FILE2 > my_grep.txt
    grep $FLAG -e 'The World' $FILE $FILE2 > grep.txt
    COMPARE="$(diff -q my_grep.txt grep.txt)"
	if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
	then
        echo "./s21_grep $FLAG -e 'The World' $FILE$ FILE2" >> fail.txt
        ((FAIL++))
	else
		((SUCCESS++))
	fi
    #rm my_grep.txt grep.txt
}
done

for FLAG in -i -v -h -s -o -c -l -n
do {
    for FLAG2 in i v h s o c l n
    do {
        echo "$FLAG$FLAG2 disagree $FILE"
        ./s21_grep $FLAG$FLAG2 disagree $FILE > my_grep.txt
        grep $FLAG$FLAG2 disagree $FILE > grep.txt
        COMPARE="$(diff -q my_grep.txt grep.txt)"
        if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
        then
            echo "./s21_grep $FLAG$FLAG2 disagree $FILE" >> fail.txt
            ((FAIL++))
        else
            ((SUCCESS++))
        fi
        #rm my_grep.txt grep.txt
    }
    done
}
done

for FLAG in -i -v -h -s -o -c -l -n
do {
    for FLAG2 in i v h s o c l n
    do {
        echo "$FLAG$FLAG2 disagree $FILE $FILE2"
        ./s21_grep $FLAG$FLAG2 disagree $FILE $FILE2 > my_grep.txt
        grep $FLAG$FLAG2 disagree $FILE $FILE2 > grep.txt
        COMPARE="$(diff -q my_grep.txt grep.txt)"
        if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
        then
            echo "./s21_grep $FLAG$FLAG2 disagree $FILE $FILE2" >> fail.txt
            ((FAIL++))
        else
            ((SUCCESS++))
        fi
        #rm my_grep.txt grep.txt
    }
    done
}
done

for FLAG in -i -v -h -s -o -c -l -n
do {
    for FLAG2 in i v h s o c l n
    do {
        echo "$FLAG$FLAG2 -e travel $FILE"
        ./s21_grep $FLAG -e travel $FILE > my_grep.txt
        grep $FLAG -e travel $FILE > grep.txt
        COMPARE="$(diff -q my_grep.txt grep.txt)"
        if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
        then
            echo "./s21_grep $FLAG -e travel $FILE" >> fail.txt
            ((FAIL++))
        else
            ((SUCCESS++))
        fi
        #rm my_grep.txt grep.txt
    }
    done
}
done

for FLAG in -i -v -h -s -o -c -l -n
do {
    for FLAG2 in i v h s o c l n
    do {
        echo "$FLAG$FLAG2 -e travel $FILE $FILE2"
        ./s21_grep $FLAG$FLAG2 -e travel $FILE $FILE2 > my_grep.txt
        grep $FLAG$FLAG2 -e travel $FILE $FILE2 > grep.txt
        COMPARE="$(diff -q my_grep.txt grep.txt)"
        if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
        then
            echo "./s21_grep $FLAG$FLAG2 -e travel $FILE $FILE2" >> fail.txt
            ((FAIL++))
        else
            ((SUCCESS++))
        fi
        #rm my_grep.txt grep.txt
    }
    done
}
done

echo "-f $FILE3 $FILE"
./s21_grep -f $FILE3 $FILE > my_grep.txt
grep -f $FILE3 $FILE > grep.txt
COMPARE="$(diff -q my_grep.txt grep.txt)"
if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
then
    echo "./s21_grep -f $FILE3 $FILE" >> fail.txt
    ((FAIL++))
else
    ((SUCCESS++))
fi
#rm my_grep.txt grep.txt

echo "-f $FILE3 $FILE $FILE2"
./s21_grep -f $FILE3 $FILE $FILE2 > my_grep.txt
grep -f $FILE3 $FILE $FILE2 > grep.txt
COMPARE="$(diff -q my_grep.txt grep.txt)"
if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
then
    echo "./s21_grep -f $FILE3 $FILE $FILE2" >> fail.txt
    ((FAIL++))
else
    ((SUCCESS++))
fi
#rm my_grep.txt grep.txt

for FLAG in -i -v -h -s -o -c -l -n
do {
    echo "$FLAG -f $FILE3 $FILE"
    ./s21_grep $FLAG -f $FILE3 $FILE > my_grep.txt
    grep $FLAG -f $FILE3 $FILE > grep.txt
    COMPARE="$(diff -q my_grep.txt grep.txt)"
	if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
	then
        echo "./s21_grep $FLAG -f $FILE3 $FILE" >> fail.txt
        ((FAIL++))
	else
		((SUCCESS++))
	fi
    #rm my_grep.txt grep.txt
}
done

for FLAG in -i -v -h -s -o -c -l -n
do {
    echo "$FLAG -f $FILE3 $FILE $FILE2"
    ./s21_grep $FLAG -f $FILE3 $FILE $FILE2 > my_grep.txt
    grep $FLAG -f $FILE3 $FILE $FILE2 > grep.txt
    COMPARE="$(diff -q my_grep.txt grep.txt)"
	if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
	then
        echo "./s21_grep $FLAG -f $FILE3 $FILE $FILE2" >> fail.txt
        ((FAIL++))
	else
		((SUCCESS++))
	fi
    #rm my_grep.txt grep.txt
}
done

for FLAG in -i -v -h -s -o -c -l -n
do {
    for FLAG2 in i v h s o c l n
    do {
        echo "$FLAG$FLAG2 -f $FILE3 $FILE"
        ./s21_grep $FLAG -f $FILE3 $FILE > my_grep.txt
        grep $FLAG -f $FILE3 $FILE > grep.txt
        COMPARE="$(diff -q my_grep.txt grep.txt)"
        if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
        then
            echo "./s21_grep $FLAG -f $FILE3 $FILE" >> fail.txt
            ((FAIL++))
        else
            ((SUCCESS++))
        fi
        #rm my_grep.txt grep.txt
    }
    done
}
done

for FLAG in -i -v -h -s -o -c -l -n
do {
    for FLAG2 in i v h s o c l n
    do {
        echo "$FLAG$FLAG2 -f $FILE3 $FILE $FILE2"
        ./s21_grep $FLAG$FLAG2 -f $FILE3 $FILE $FILE2 > my_grep.txt
        grep $FLAG$FLAG2 -f $FILE3 $FILE $FILE2 > grep.txt
        COMPARE="$(diff -q my_grep.txt grep.txt)"
        if  [ "$COMPARE" == "Files my_grep.txt and grep.txt differ" ]
        then
            echo "./s21_grep $FLAG$FLAG2 -f $FILE3 $FILE $FILE2" >> fail.txt
            ((FAIL++))
        else
            ((SUCCESS++))
        fi
        #rm my_grep.txt grep.txt
    }
    done
}
done

echo "SUCCESS: $SUCCESS"
echo "FAIL: $FAIL"
