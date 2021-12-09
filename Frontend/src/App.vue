<template>
  <div>
    <v-container>
      <header>
        <p class="title">Närvarokollen</p>
        <div id="nav">
          <router-link
            class="button"
            to="/"
          >Närvaro</router-link>
          <router-link
            class="button"
            to="/login"
          >Login</router-link>
        </div>
      </header>
    </v-container>
    <v-content>
      <router-view />
    </v-content>
  </div>
</template>

<style>
#nav {
  text-align: right;
  font-weight: lighter;
  justify-content: right;
}

#nav a {
  color: black;
}

#nav a.router-link-exact-active {
  color: black;
}

header {
  left: 0;
  top: 0;
  background-color: #85b3d1ff;
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 0px 30px;
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  color: black;
}

body {
  margin: 0%;
}

@keyframes buttons {
  from {
    background-color: #85b3d1ff;
  }
  to {
    background-color: rgb(170, 218, 250);
  }
}

.title {
  font-size: 30px;
  font-weight: bold;
}

.button {
  padding: 15px;
  margin: 0px 10px;
  border-radius: 10px;
  text-decoration: none;
  font-size: 20px;
}

.button:hover {
  animation-name: buttons;
  animation-duration: 0.8s;
}
</style>
