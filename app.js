const Botkit = require('botkit')

const config = require('./config.json')

const controller = Botkit.slackbot({
  debug: config.debug
})

const bot = controller.spawn({
  token: config.bot_token
}).startRTM()

controller.hears(['hello', 'hi'], 'direct_message, direct_mention, mention', function (bot, message) {
  bot.api.reactions.add({
    timestamp: message.ts,
    channel: message.channel,
    name: 'robot_face'
  }, (err, res) => {
    if (err) {
      bot.botkit.log('Failed to add emoji reaction :(', err)
    }
  })

  bot.reply(message, 'Hello.')

})

controller.hears(['shutdown'], 'direct_message,direct_mention,mention', function (bot, message) {
  bot.startConversation(message, function (err, convo) {
    if (err) {
      console.err(err)
    }

    convo.ask('Are you sure you want me to shutdown?', [
      {
        pattern: bot.utterances.yes,
        callback: function (response, convo) {
          convo.say('Bye!')
          convo.next()
          setTimeout(() => {
            process.exit()
          }, 3000)
        }
      },
      {
        pattern: bot.utterances.no,
        default: true,
        callback: function (response, convo) {
          convo.say('*Phew!*')
          convo.next()
        }
      }
    ])
  })
})