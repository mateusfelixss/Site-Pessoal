const express = require('express')
const app = express()

app.get('/index')

const PORT = process.env.PORT || 5000;
app.listen(PORT, () => {
    console.log("Listening on port " + PORT)
})