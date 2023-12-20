async function findCountries(region, keyword){
    // const apiurl = `https://jsonmock.hackerrank.com/api/countries`;

    // const resp = await axios.get(`${apiurl}/search?region=${region}&name=${keyword}`);
    // const tp = resp.data.tota_pages;
    const tp = 1;
    const countries = [];
    
    for(let i = 1; i<=tp; i++){
        // const res = await axios.get(`${apiurl}/search?region=${region}&name=${keyword}&page=${i}`);
        // const data = res.data.data;
        const data = COUNTRIES_DATA.data;

        data.forEach(d=>{
            const cnt = d.name;
            const popl = d.population;
            const ans = d.name + ',' + d.population;
            countries.push(ans);
        })
    }

    countries.sort((a,b)=>{
        const popA = parseInt(a.split(',')[1]);
        const popB = parseInt(b.split(',')[1]);
        
        if(popA != popB){
            return popB - popA;
        }
        else{
            return (a.split(',')[0]).localeCompare(b.split(',')[0]);
        }
    })

    for(let i = 0; i<countries.length; i++){
        console.log(countries[i]);
    }
}

findCountries('asia', 'in');

// THIS IS THE ORIGINAL FUNCTION MADE FOR ORACLE QUESTION:
// async function findCountries(region, keyword){
//     const apiurl = `https://jsonmock.hackerrank.com/api/countries`;


//     const resp = await axios.get(`${apiurl}/search?region=${region}&name=${keyword}`);
//     const tp = resp.data.tota_pages;
//     const countries = [];
    
//     for(let i = 1; i<=tp; i++){
//         const res = await axios.get(`${apiurl}/search?region=${region}&name=${keyword}&page=${i}`);
//         const data = res.data.data;

//         data.forEach(d=>{
//             const cnt = d.name;
//             const popl = d.population;
//             const ans = d.name + ',' + d.population;
//             countries.push(ans);
//         })
//     }

//     countries.sort((a,b)=>{
//         const popA = parseInt(a.split(',')[1]);
//         const popB = parseInt(b.split(',')[1]);
        
//         if(popA != popB){
//             return popB - popA;
//         }
//         else{
//             return (a.split(',')[0]).localeCompare(b.split(',')[0]);
//         }
//     })
// }