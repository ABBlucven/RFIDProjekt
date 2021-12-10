import Vue from 'vue'
import App from './App.vue'
import router from '../src/router'
import { rtdbPlugin } from 'vuefire'

// import firebase from 'firebase/compat/app'

// const config = {
//   apiKey: "AIzaSyAFlBRaG2F3sqwOnrKcpLPsdnpmBrz9CR0",
//   authDomain: "rfid-project-e703f.firebaseapp.com",
//   databaseURL: "https://rfid-project-e703f-default-rtdb.europe-west1.firebasedatabase.app",
//   projectId: "rfid-project-e703f",
//   storageBucket: "rfid-project-e703f.appspot.com",
//   messagingSenderId: "908754453649",
//   appId: "1:908754453649:web:896de55f55cb4d635beb30",
//   measurementId: "G-VQJTL7670B"
// }

// firebase.initializeApp(config)

Vue.use(rtdbPlugin)

Vue.config.productionTip = false

new Vue({
  router,
  render: h => h(App)
}).$mount('#app')
