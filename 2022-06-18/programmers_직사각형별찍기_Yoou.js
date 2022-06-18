process.stdin.setEncoding('utf8');
process.stdin.on('data', data => {
    const n = data.split(" ");
    const a = Number(n[0]), b = Number(n[1]);
    let ret = '';
    for(let i = 0; i < b; i++)
    {
        for(let j = 0; j < a; j++)
            ret += '*';
        ret += '\n';
    }
    console.log(ret);
});

// process.stdin.setEncoding('utf8');
// process.stdin.on('data', data => {
//     const n = data.split(" ");
//     const a = Number(n[0]), b = Number(n[1]);
//     let ret = '*'.repeat(a);
//     for(let i = 0; i < b; i++)
//         console.log(ret);
// });