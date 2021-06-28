var allNames = {};
function retrieveAllPerson(){
    //** Total Number of Person in the Database and convert to Int */
    totalPerson = parseInt(document.getElementById("totalPerson").innerHTML.substring(19,));
    for (let index = 1; index < totalPerson; index++) {
        //** Request to get All Names accross all generated files  */
        let xhr = new XMLHttpRequest();
        xhr.open("GET", `application://xhtml+xml/file/C:/Users/Soydemir/Documents/Algorithmique/Github/export/${index.toString()}.html`)
        //xhr.open("GET", `${index.toString()}.html`);
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

function retrievePersonFromFile(data, index){
    const nameTable = data.querySelector("a");
    //** Pushing each name into an array */
    allNames[index] = nameTable.innerHTML;
    console.log(allNames);
}


function foundPerson(){
    //** Button Search  */
    btn = document.getElementById("searchBtn");

    //** Total Number of Person in the Database and convert to Int */
    totalPerson = parseInt(document.getElementById("totalPerson").innerHTML.substring(19,));

    //** Value of the Input that contains First Name */
    personToSearch = document.querySelector("input").value;
    
    for (let index = 1; index < totalPerson; index++) {
        console.log(allNames[index]);
        if (allNames[index] === personToSearch) {
            window.open(`${index.toString()}.html`, "_blank");
            btn.style.background = "rgba(0, 230, 64, 1)";
            break;
        } else{
            btn.style.background = "red";
        }
    }
}

retrieveAllPerson()
