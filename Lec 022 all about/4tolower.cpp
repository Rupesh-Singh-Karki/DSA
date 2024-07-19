char toLowerCase(char ch) {
    if((ch >='a' && ch <='z')||(ch >='0' && ch <='9'))
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}