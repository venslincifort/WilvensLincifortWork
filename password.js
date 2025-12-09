// Wilvens Lincifort
// Leon Zou
// Dave Etienne
// Farhana Akter


let Input = document.getElementById("password-input");
let result = document.getElementById("result");        // UL for weaknesses
let strengthTitle = document.getElementById("strength-title"); // H1 label

const commonPasswords = [
  "123456",
  "password",
  "123456789",
  "12345",
  "qwerty",
  "12345678",
  "111111",
  "123123",
  "abc123",
  "password1",
  "000000",
  "iloveyou",
  "1234",
  "1q2w3e4r",
  "qwerty123",
  "1234567",
  "dragon",
  "letmein",
  "football",
  "monkey",
  "john",
  "john1",
  "shadow",
  "master",
  "696969",
  "superman",
  "hello",
  "welcome",
  "ninja",
  "baseball",
  "sunshine",
  "princess",
  "admin",
  "admin123",
  "admin123456",
  "123admin",
  "adminabc",
  "login",
  "trustno1",
  "hunter",
  "cookie",
  "whatever",
  "qazwsx",
  "asdfgh",
  "batman",
  "mustang",
  "111222",
  "121212",
  "7777777",
  "1qaz2wsx",
  "qaz123",
  "passw0rd",
  "zxcvbnm",
  "555555",
  "zaq12wsx",
  "starwars",
  "987654321",
  "666666",
  "112233",
  "123qwe",
  "qwe123",
  "killer",
  "jordan23",
  "hardcore",
  "999999",
  "freedom",
  "qwert",
  "matrix",
  "charlie",
  "q1w2e3r4",
  "888888",
  "daniel",
  "qazxsw",
  "buster",
  "11111111",
  "1g2w3e4r",
  "george",
  "102030",
  "1q2w3e",
  "qwertyuiop",
  "trust",
  "summer",
  "computer",
  "tigger",
  "jennifer",
  "thunder",
  "access",
  "welcome1",
  "qazwsxedc",
  "cheese",
  "merlin",
  "secret",
  "qazwsxedc123",
  "testing",
  "canthackme",
  "abcdefg",
  "123abc",
  "a1b2c3",
  "1a2b3c",
  "aabbcc",
  "aa1bb2cc3",
  "p@ssw0rd",
  "default",
  "default123",
  "defaultabc",
  "passkey123",
  "keyboard",
  "hockey",
  "catsanddogs",
  "dallas",
  "silver",
  "internet",
  "purple",
  "blahblah",
  "peanut",
  "sparrow",
  "q1w2e3",
  "happy",
  "pokemon",
  "blink182",
  "hackthis"
];

function checkCommonPassword(password) {
    if (commonPasswords.includes(password.toLowerCase())) {
        return "Commonly used password, try a different password";
    }
    return true;
}




// Check if a password contains certain characters using regex
// regex just sees if a character is present or not

function checkCases(password, regex, label) {
    if (regex.test(password)) {
        return true;
    } else {
        return `${label} is missing`;
    }
}
// the checkCases sees if any of the characters are present in the password
// lowercase letters
function checkLowerCase(password){
    return checkCases(password, /[a-z]/, "Lowercase letter");
}
//capital letters
function checkUpperCase(password){
    return checkCases(password, /[A-Z]/, "Uppercase letter");
}
//numbers
function checkNumbers(password){
    return checkCases(password, /[0-9]/, "Number");
}
//special symbols
function checkSpecialSymbols(password){
    return checkCases(password, /[^a-zA-Z0-9\s]/, "Special symbol");
}
// This checks if the password is at least 8 characters long
// i set it to true so it can be appended to the strength calculation later
function checkLength(password){

    if(password.length  < 8){
       return{ isValid: false, message: "Password length is too short, has to be at least 8 letters"}
    }
    
        else if(password.length < 12){
        return{ isValid: false, message: "Password length is medium, try to make it at least 12 letters"}
    }
  else if(password.length > 12){
       return{ isValid: true, message:""}
    }

}

   

// basically my list of true or false statements based on if theyre present or not
function weakNess(password){
    return [
        checkLowerCase(password),
        checkUpperCase(password),
        checkNumbers(password),
        checkSpecialSymbols(password),
        checkLength(password),
        checkCommonPassword(password)
    ];
}
// my onclick function that checks the password strength

function checkPassword(password){
    let weaknesses = weakNess(password);
    let strength = 0;

    // Check if common password — invalidate immediately
    if (weaknesses.includes("Commonly used password, try a different password")) {
        result.innerHTML = "";
        strengthTitle.style.color = "red";
        strengthTitle.innerText = "Invalid Password";

        const li = document.createElement("li");
        li.innerText = "Commonly used password, try a different password";
        result.appendChild(li);

        return; // stop here
    }

    // Normal weakness rendering
    result.innerHTML = "";

    weaknesses.forEach(weakness => {
        if (weakness === true || weakness.isValid === true){
            strength++;
        } else {
            const li = document.createElement("li");
            li.innerText = weakness.message || weakness;
            result.appendChild(li);
        }
    });

    // Strength title
    if (strength <= 2){
        strengthTitle.style.color = "red";
        strengthTitle.innerText = "Weak Password";
    } 
    else if (strength === 3 || strength === 4){
        strengthTitle.style.color = "orange";
        strengthTitle.innerText = "Medium Strength Password";
    }
    else {
        strengthTitle.style.color = "green";
        strengthTitle.innerText = "Strong Password";
    }
}


