#!/usr/bin/node

const request = require('request');



request(
  `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`,
  (err, response, body) => {
    if (err) {
      throw err;
    } else {
      const chars = JSON.parse(body).characters;
      for (let i = 0; i < chars.length; i++) {
        request(chars[i], (err, response, body) => {
          if (err) {
            throw err;
          } else {
            console.log(JSON.parse(body).name);
          }
        });
      }
    }
  }
);