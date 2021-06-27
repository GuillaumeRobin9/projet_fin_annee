function unknownPerson(){
    const personID = document.getElementsByClassName("name");
    const personLastName = document.getElementsByClassName("lastName");
    const birth = document.getElementsByClassName("birthDay");
    const region = document.getElementsByClassName("region");
    const links = document.querySelectorAll("a");
    console.log(links);

    for (let index = 0; index < personID.length; index++) {
        if (personID[index].innerHTML === "Name : -") {
            personID[index].innerHTML = "Unknown Identity :("
            personLastName[index].innerHTML = "Unknown Last Name :("
            birth[index].innerHTML = "Unknown Birth Date :("
            region[index].innerHTML = "Unknown Region :("
        }
        if (links[index].innerHTML === "- Tree") {
            links[index]["href"] = "index.html";
            links[index].innerHTML = "No Link.."
        }    
    }



}

unknownPerson()
