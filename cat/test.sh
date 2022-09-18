#!/bin/sh

FILE="text.txt"
SUCCESS=0
FAIL=0
echo "" > fail.txt

for FLAG in -e -n -s -t -v -b
do {
    echo "$FLAG $FILE"
    ./s21_cat $FLAG $FILE > my_cat.txt
    cat $FLAG $FILE > cat.txt
    COMPARE="$(diff -q my_cat.txt cat.txt)"
	if  [ "$COMPARE" == "Files my_cat.txt and cat.txt differ" ]
	then
        echo "./s21_cat $FLAG $FILE" >> fail.txt
        ((FAIL++))
	else
		((SUCCESS++))
	fi
    rm my_cat.txt cat.txt
}
done

for FLAG in -E -T --number-nonblank --number --squeeze-blank
do {
    echo "$FLAG $FILE"
    ./s21_cat $FLAG $FILE > my_cat.txt
    cat $FLAG $FILE > cat.txt
    COMPARE="$(diff -q my_cat.txt cat.txt)"
	if  [ "$COMPARE" == "Files my_cat.txt and cat.txt differ" ]
	then
        echo "./s21_cat $FLAG $FILE" >> fail.txt
        ((FAIL++))
	else
		((SUCCESS++))
	fi
    rm my_cat.txt cat.txt
}
done

echo "SUCCESS: $SUCCESS"
echo "FAIL: $FAIL"
