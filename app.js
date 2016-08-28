const Botkit = require('botkit')
const FaceBomber = require('./build/Release/FaceBomber')

const obj = new FaceBomber.FaceBomberWrapper()
obj.sayHello()

const config = require('./config.json')

const controller = Botkit.slackbot({
  debug: config.debug
})

const bot = controller.spawn({
  token: config.bot_token
}).startRTM()

controller.hears(['hello', 'hi'], 'direct_mention,direct_message,mention', function (bot, message) {
  bot.reply(message, ':new_moon_with_face: :bomb:')
})

controller.hears(['facebomb'], ['direct_mention,direct_message'], function (bot, message) {
  bot.reply(message, 'I\'m gonna do facebomb! :bomb:')
})

controller.hears(['add face to bomb'], ['direct_mention,direct_message'], function (bot, message) {
  bot.reply(message, 'New victim! Wohooo! :unicorn_face:')
})