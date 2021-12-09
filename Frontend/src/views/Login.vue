<template>
  <div id="app">
    <div class="login-page">
      <transition name="fade">
        <div
          v-if="!registerActive"
          class="wallpaper-login"
        ></div>
      </transition>

      <div class="container">
        <div class="row">
          <div
            v-if="!registerActive"
            class="card login"
            v-bind:class="{ error: emptyFields }"
          >
            <h1>Sign In</h1>
            <form class="form-group">
              <input
                v-model="email"
                type="email"
                class="form-control"
                placeholder="Email"
                required
              >
              <input
                v-model="password"
                type="password"
                class="form-control"
                placeholder="Password"
                required
              >
              <button
                type="submit"
                class="btn"
                @click="login"
              >Logga in</button>

              <!-- <p>Don't have an account? <a
                  href="#"
                  @click="registerActive = !registerActive, emptyFields = false"
                >Sign up here</a>
              </p>
              <p><a href="#">Forgot your password?</a></p> -->
            </form>
          </div>

          <!-- <div
            v-else
            class="card register"
            v-bind:class="{ error: emptyFields }"
          >
            <h1>Sign Up</h1>
            <form class="form-group">
              <input
                v-model="emailReg"
                type="email"
                class="form-control"
                placeholder="Email"
                required
              >
              <input
                v-model="passwordReg"
                type="password"
                class="form-control"
                placeholder="Password"
                required
              >
              <input
                v-model="confirmReg"
                type="password"
                class="form-control"
                placeholder="Confirm Password"
                required
              >
              <input
                type="submit"
                class="btn btn-primary"
                @click="doRegister"
              >
              <p>Already have an account? <a
                  href="#"
                  @click="registerActive = !registerActive, emptyFields = false"
                >Sign in here</a>
              </p>
            </form>
          </div> -->
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import firebase from '../db'

export default {

  data () {
    return {
      // registerActive: false,
      email: "",
      password: "",
      // emailReg: "",
      // passwordReg: "",
      // confirmReg: "",
      emptyFields: false
    }
  },

  methods: {
    login () {
      firebase.auth().signInWithEmailAndPassword(this.email, this.password).then(
        function (user) {
          alert('Du är nu inloggad!')
          alert(user)
        },
        function (err) {
          alert('Fel!', err.message)
        }
      )
    },

    // doRegister () {
    //   if (this.emailReg === "" || this.passwordReg === "" || this.confirmReg === "") {
    //     this.emptyFields = true
    //   } else {
    //     alert("You are now registered")
    //   }
    // }
  }
}
</script>

<style>
#app {
  text-align: center;
  font-family: Arial, sans-serif;
}

p {
  line-height: 20px;
}

.btn {
  padding: 5px 10px;
  border: none;
  border-radius: 5px;
  background-color: white;
}
.btn:hover {
  background-color: rgb(121, 121, 121);
  color: white;
}
.card {
  padding: 20px;
  margin: 100px auto;
  min-width: 400px;
  background-color: #b3c7d6ff;
  border-radius: 50px;
}

.form-group input {
  margin: 20px auto;
  display: block;
}

.form-control {
  padding: 10px;
  border: none;
  border-radius: 5px;
}

.login-page {
  align-items: center;
  justify-content: center;
  display: flex;
}
/* 
   .wallpaper-login {
      background: url(https://images.pexels.com/photos/32237/pexels-photo.jpg?auto=compress&cs=tinysrgb&dpr=2&h=750&w=1260)
         no-repeat center center;
      background-size: cover;
      height: 100%;
      position: absolute;
      width: 100%;
   } */

.fade-enter-active,
.fade-leave-active {
  transition: opacity 0.5s;
}
.fade-enter,
.fade-leave-to {
  opacity: 0;
}

/* .wallpaper-register {
      background: url(https://images.pexels.com/photos/533671/pexels-photo-533671.jpeg?auto=compress&cs=tinysrgb&dpr=2&h=750&w=1260)
         no-repeat center center;
      background-size: cover;
      height: 100%;
      position: absolute;
      width: 100%;
      z-index: -1; */
/* } */

h1 {
  margin-bottom: 20px;
}

.error {
  animation-name: errorShake;
  animation-duration: 0.3s;
}

@keyframes errorShake {
  0% {
    transform: translateX(-25px);
  }
  25% {
    transform: translateX(25px);
  }
  50% {
    transform: translateX(-25px);
  }
  75% {
    transform: translateX(25px);
  }
  100% {
    transform: translateX(0);
  }
}
</style>