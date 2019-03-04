var fs = require('fs');

fs.writeFile('mynewfile3', 'This is my replacing text', function (err) {
    if (err) throw err;
    console.log('Replaced!')
})