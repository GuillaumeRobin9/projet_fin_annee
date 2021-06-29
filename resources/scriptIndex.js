//
// Project: projet_fin_annee
// Authors: Antoine SOYDEMIR
// Creation date: 25/06/2021
// Modification date: 29/06/2021
// Role: Javascript Functions to dynamically render specific option on the page.
//


//** Function who detects automatically all unknown person  */
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

//** Function that listen each bubble and start all proccess to get region infos */
function clicked(id){

    //** Parsing Bubble Inputs */
    let info = document.getElementById(id);
    let infobulle = info.getElementsByClassName("infobulle");
    const region = info.getElementsByClassName("region")[0].innerHTML
    const location = infobulle[0].children[0];
    const latitude = infobulle[0].children[1];
    const longitude = infobulle[0].children[2];

    //** INFO BUBBLE UPDATES */
    getRegionInformations(region.substring(8,), location, latitude, longitude);
}


//** Send HTTPS Request to OpenWeather API to get informations about the region */
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

//** Parsing OpenWeather API Response and replace it in the HTML */
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

unknownPerson()
