var allNames = {};
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
    const nameTable = data.querySelectorAll("a")[3];
    //** Pushing each name into an array */
    allNames[index] = nameTable.innerHTML;
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
    window.open(`${random}.html`, "_blank");
}

retrieveAllPerson()
