function unknownPerson(){
    const personID = document.getElementsByClassName("name");
    const personLastName = document.getElementsByClassName("lastName");
    const birth = document.getElementsByClassName("birthDay");
    const region = document.getElementsByClassName("region");
    const links = document.querySelectorAll("a");

    for (let index = 0; index < personID.length; index++) {
        if (personID[index].children[0].innerHTML === "-") {
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

function getRegionInformations(region, location, latitude, longitude){

    let xhr = new XMLHttpRequest();
    xhr.open("GET", `https://api.openweathermap.org/data/2.5/weather?q=${region}&appid=840322c4444cb74f0403b138879badea`);
    xhr.onload = function () {
        switch (xhr.status){
        case 200:
            parseData(JSON.parse(xhr.responseText), location, latitude, longitude);
            break;
        default:
            console.log("FAILED AT PARSING DATA");
            parseData(JSON.parse(xhr.responseText), location, latitude, longitude);
        }
    }
    xhr.send();

}

function parseData(data, location, latitude, longitude){
    //** Updating Values */
    if (data["cod"] === "404") {
        console.log("ENTERED HERE");
        location.innerHTML = `Not Found..`;
        latitude.innerHTML = `Not Found..`;
        longitude.innerHTML = `Not Found..`;
    } else{
        location.innerHTML = `Located in : ${data["sys"]["country"]}`;
        latitude.innerHTML = `Latitude is : ${data["coord"]["lat"]}`;
        longitude.innerHTML = `Longitude is : ${data["coord"]["lon"]}`;
    }

}

function clicked(id){

    //** Parsing Bubble Inputs */
    let fatherInfos = document.getElementById(id);
    let infobulle = fatherInfos.getElementsByClassName("infobulle");
    const region = fatherInfos.getElementsByClassName("region")[0].innerHTML
    const location = infobulle[0].children[0];
    const latitude = infobulle[0].children[1];
    const longitude = infobulle[0].children[2];
    
    //** INFO BUBBLE UPDATES */
    getRegionInformations(region.substring(8,), location, latitude, longitude);
}

unknownPerson()
