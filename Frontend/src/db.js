// // Get a RTDB instance
import firebase from 'firebase/compat/app'
import 'firebase/compat/database'

// const firebaseConfig = {
//   apiKey: "AIzaSyAFlBRaG2F3sqwOnrKcpLPsdnpmBrz9CR0",
//   authDomain: "rfid-project-e703f.firebaseapp.com",
//   databaseURL: "https://rfid-project-e703f-default-rtdb.europe-west1.firebasedatabase.app",
//   projectId: "rfid-project-e703f",
//   storageBucket: "rfid-project-e703f.appspot.com",
//   messagingSenderId: "908754453649",
//   appId: "1:908754453649:web:896de55f55cb4d635beb30",
//   measurementId: "G-VQJTL7670B"
// };

// // Initialize Firebase

// import firebase from '@firebase/app'
// import * as firebase from "firebase/app"
// import '@firebase/RTDB'
// import 'firebase/auth'

const config = {
  apiKey: "AIzaSyAFlBRaG2F3sqwOnrKcpLPsdnpmBrz9CR0",
  authDomain: "rfid-project-e703f.firebaseapp.com",
  databaseURL: "https://rfid-project-e703f-default-rtdb.europe-west1.firebasedatabase.app",
  projectId: "rfid-project-e703f",
  storageBucket: "rfid-project-e703f.appspot.com",
  messagingSenderId: "908754453649",
  appId: "1:908754453649:web:896de55f55cb4d635beb30",
  measurementId: "G-VQJTL7670B"
}

// const settings = {
//   timestampsInSnapshots: true
// }

export const db = firebase.initializeApp(config).database()

// firebase.initializeApp(config)
// const db = firebase.firestore()
// db.settings(settings)

// export default db
export { firebase }