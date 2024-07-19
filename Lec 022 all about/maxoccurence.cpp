char getMaxOccCharacter(string s) {

    int arr[26] = {0};


    //create an array of count of characters
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        //lowercase
        int number = 0;  //yaha khali lowercase hoga patah hai warna dono ka case banega
        number = ch - 'a';  //converts char into index
        arr[number]++; //adds number at the designated char index
    }

    //find maximum occ character
    int maxi = -1, ans = 0;
    for(int i=0;i<26; i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }
    

    return 'a'+ans; //yaha index ko phirse char bana diya

}
