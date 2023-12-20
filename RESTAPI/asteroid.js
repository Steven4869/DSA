async function asteroidOrbit(year, orbitclass) {
    // const apiUrl = `https://json.hackerrank.com/api/asteroids`;

    // const res = await axios.get(`${apiUrl}/search?orbit_class=${orbitclass}&page=1`);
    // const tp = res.data.total_pages;
    const res = ASTEROID_DATA
    const tp = 1;       // we have only one page in constants.js
    const designations = [];

    for(let i = 1; i<=tp; i++){
        // const response = await axios.get(`${apiUrl}&page=${i}`);
        const response = ASTEROID_DATA;
        const data = response.data;    // 'const' variable can also be sorted

        data.sort((a, b)=>{
            const periodA = parseFloat(a.period_yr) || 1;
            const periodB = parseFloat(b.period_yr) || 1;

            if(periodA != periodB){
                return periodA - periodB; // If the difference is negative, it means that periodA is smaller and should come before periodB in the sorted order. If the difference is positive, it means that periodA is larger and should come after periodB. If the difference is 0, it means the periods are equal and their order remains unchanged
            }
            else{
                return a.designation.localeCompare(b.designation); // 'localCompare' compares two strings in lexigoraphic way
            }
        })

        data.forEach(d=>{
            const date=d.discovery_date;
            const thisyear = date.substring(0, 4);   // Extracts the first 4 elements starting from 0th index
            // Or, const year = date.split("-")[0]; // splits the string to form an array and extracts the first element(year)

            if(parseInt(thisyear)===year){
                designations.push(d.designation);
            }
        })
    }
    designations.forEach(d=>{
        console.log(d);
    });
}


asteroidOrbit(2010, 'aten');



// ORIGINAL FUNCTION WRITTEN FOR THE ORACLE QUESTION:
// async function asteroidOrbit(year, orbitclass) {
//     const apiUrl = `https://json.hackerrank.com/api/asteroids`;

//     const res = await axios.get(`${apiUrl}/search?orbit_class=${orbitclass}&page=1`);
//     const tp = res.data.total_pages;
//     const designations = [];

//     for(let i = 1; i<=tp; i++){
//         const response = await axios.get(`${apiUrl}&page=${i}`);
//         const data = response.data.data;    // 'const' variable can also be sorted

//         data.sort((a, b)=>{
//             const periodA = parseFloat(a.period_yr) || 1;
//             const periodB = parseFloat(b.period_yr) || 1;

//             if(periodA != periodB){
//                 return periodA - periodB; // If the difference is negative, it means that periodA is smaller and should come before periodB in the sorted order. If the difference is positive, it means that periodA is larger and should come after periodB. If the difference is 0, it means the periods are equal and their order remains unchanged
//             }
//             else{
//                 return a.designation.localeCompare(b.designation); // 'localCompare' compares two strings in lexigoraphic way
//             }
//         })

//         data.forEach(d=>{
//             const date=d.discovery_date;
//             const thisyear = date.substring(0, 4);   // Extracts the first 4 elements starting from 0th index
//             // Or, const year = date.split("-")[0]; // splits the string to form an array and extracts the first element(year)

//             if(parseInt(thisyear)===year){
//                 designations.push(d.designation);
//             }
//         })
//     }
//     designations.forEach(d=>{
//         console.log(d);
//     });
// }

// QUESTION:
// Use the HTTP GET method to retrieve information from a database of asteroids.
// Query https://jsonmock.hackerrank.com/api/asteroids to find all the records. To use the search feature, add /search? 
// followed by a parameter and keyword, which is case insensitive. 
// If the keyword exists in the parameter's value, it is included in the response. 
// For example, https://jsonmock.hackerrank.com/api/asteroids/search?parameter=(keyword). 
// The query result is paginated and can be further accessed by appending to the
//  query string? page=num, where num is the page number. 
// The response is a JSON object with the following five fields: 
// • page:The current page of the results. (Number) 
// • per_page: The maximum number of results returned per page. (Number) 
// • total: The total number of results. (Number) 
// • total_pages:The total number of pages with results. (Number) 
// • data: Either an empty array or an array of asteroid records. 

// In data, each asteroid object has the following schema: 
// • designation: The name of the asteroid(String) 
// • discovery date: The date of the discovery(String) 
// • period yr: The period of rotation in years(String). 
// • orbit class: Orbital class of the asteroid(String) 
// Given the year of discovery and the value of orbit_class, filter the results 
// and sort on the period yr parameter.Note that orbitclass contains a keyword
// that should be present in the asteroid's orbit class parameter. In case of a tie,
//  sort on its designation ascending. Return the list of designations. 
//  If period yr does not exist for an asteroid, assume its value as 1 

// Function Description 
// Complete the function asteroidOrbit in the editor below.
// asteroidOrbit has the following parameter(s): 
// • integer year: year of discovery to filter 
// • string orbitclass, the keyword of orbit class to filter

// Return
// string[]: the list of asteroid designations 
