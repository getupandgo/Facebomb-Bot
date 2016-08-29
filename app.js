'use strict'

const Botkit = require('botkit')

const FaceBomber = require('./build/Release/FaceBomber')
const config = require('./config.json')

const imageUrlPattern = /(https?:\/\/.*\.(?:png|jpg))/gi

const controller = Botkit.slackbot({
  debug: config.debug
})

// spawning bot
controller.spawn({
  token: config.bot_token
}).startRTM()

const bomber = new FaceBomber.FaceBomberWrapper()

controller.hears(['hello', 'hi'], 'direct_mention,direct_message,mention', function (bot, message) {
  bomber.sayHello() // TODO: debug one
  bot.reply(message, ':new_moon_with_face: :bomb:')
})

controller.hears(['facebomb'], ['direct_mention,direct_message'], function (bot, message) {
  let pictureUrl = message.text.match(imageUrlPattern)
  let response = ''

  if (pictureUrl && pictureUrl.length) {
    if (pictureUrl.length > 1) {
      console.log('Applying only one picture at a time - getting first one')
      pictureUrl = pictureUrl[0]
    }

    console.log('processing image...')
    // const success = bomber.doFacebomb(pictureUrl)
    // if (!success) {
    //   console.log('no faces found!')
    // }

    response = 'I\'m gonna do facebomb! :bomb:'
  } else {
    response = 'Provide me url on image to bomb!'
  }

  bot.reply(message, response)
})

controller.hears(['add face to bomb'], ['direct_mention,direct_message'], function (bot, message) {
  let faceUrl = message.text.match(imageUrlPattern)
  let response = ''

  if (faceUrl && faceUrl.length) {
    if (faceUrl.length > 1) {
      console.log('Applying only one face at a time - getting first one')
      faceUrl = faceUrl[0]
    }

    console.log('processing image...')
    // const success = bomber.addFaceToBomb(faceUrl)
    // if (!success) {
    //   console.log('no faces found!')
    // }

    response = 'New victim! Wohooo! :unicorn_face:'
  } else {
    response = 'Provide me url on my new victim!'
  }

  bot.reply(message, response)
})
