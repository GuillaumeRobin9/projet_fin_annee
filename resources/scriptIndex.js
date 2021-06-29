//
// Project: projet_fin_annee
// Authors: Antoine SOYDEMIR
// Creation date: 25/06/2021
// Modification date: 29/06/2021
// Role: Javascript Functions who performs additional options
//


//** Global variable which hold all names across all html files */
var allNames = {};
var regions = {};

function retrieveAllPerson(){
    //** Total Number of Person in the Database and convert to Int */
    let totalPerson = parseInt(document.getElementById("totalPerson").innerHTML.substring(50,));
    for (let index = 1; index < totalPerson; index++) {
        //** Request to get All Names accross all generated files  */
        let xhr = new XMLHttpRequest();
        xhr.open("GET", `${index.toString()}.html`);
        xhr.onload = function () {
            switch (xhr.status){
            case 200:
                const txt = xhr.responseText;
                var stringToHTML = function (str) {
                    var parser = new DOMParser();
                    var doc = parser.parseFromString(str, 'text/html');
                    return doc;
                };
                const htmlPage = stringToHTML(txt)
                retrievePersonFromFile(htmlPage, index);
                break;
            default:
                console.log("FAILED AT PARSING DATA");
            }
        }
        xhr.send();
    }
}

//** Function who place all names with index into a list */
function retrievePersonFromFile(data, index){
    const nameTable = data.querySelectorAll("a")[2];
    //** Pushing each name into an array */
    allNames[index] = nameTable.innerHTML;
    regions[index] = data.querySelector("#personBubble > div.region").innerText.substring(9,).replace("\n", "");
    console.log(allNames);
}


//** Function to found a specific person in the Tree */
function foundPerson(){
    //** Button Search  */
    let btn = document.getElementById("searchBtn");

    //** Total Number of Person in the Database and convert to Int */
    let totalPerson = parseInt(document.getElementById("totalPerson").innerHTML.substring(50,));

    //** Value of the Input that contains First Name */
    let personToSearch = document.querySelector("input").value;
    
    for (let index = 1; index < totalPerson; index++) {
        if (allNames[index] === personToSearch) {
            window.open(`${index.toString()}.html`, "_blank");
            btn.style.background = "rgba(0, 230, 64, 1)";
            break;
        } else{
            btn.style.background = "red";
        }
    }
}

//** Function to return a random person from all files */
function randomPerson(){
    //** Total Number of Person in the Database and convert to Int */
    let totalPerson = parseInt(document.getElementById("totalPerson").innerHTML.substring(50,));
    //** Using Math() to get a random int  */
    const random = Math.floor(Math.random() * (totalPerson - 1) + 1);

    //** Opening the Person page in a new window */
    window.open(`${random}.html`, "_blank");
}


function foundRegion(){
    //** Button Search  */
    let btn = document.getElementById("regionBtn");

    //** Total Number of Person in the Database and convert to Int */
    let totalPerson = parseInt(document.getElementById("totalPerson").innerHTML.substring(50,));

    //** Value of the Input that contains First Name */
    let regionToSearch = document.querySelectorAll("input")[1];
    
    let personInRegion = [];
    for (let index = 1; index < totalPerson; index++) {
        if (regions[index] === regionToSearch.value) {
            personInRegion.push(index);
            btn.style.background = "rgba(0, 230, 64, 1)";
        }
    }
    //** Setting up Color Button to Red if anyone came from the entered Region */
    if (personInRegion.length === 0) {
        btn.style.background = "red";
        return
    }
    
    const getResultDiv = document.getElementById("regionValue");
    getResultDiv.innerHTML = `Found ${personInRegion.length} Person in this Region !\n<br>`;
    for (let index = 0; index < personInRegion.length; index++) {
        getResultDiv.innerHTML += `<a href="${personInRegion[index]}.html" target="_blank">Person ${personInRegion[index]} Link\n<br>`;
        
    }
    

}



retrieveAllPerson();
