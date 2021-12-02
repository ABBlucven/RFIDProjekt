<template>
  <div>
    <v-container>
      <header>
        <div id="app">
          <div id="nav">
            <router-link to="/" class="knapp">Närvaro</router-link> |
            <router-link to="/login" class="knapp">Login</router-link>
          </div>
        </div>
      </header>
    </v-container>
    <v-content>
      <router-view />
    </v-content>
  </div>
</template>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: black;
}

#nav {
  padding: 30px;
}

#nav a {
  font-weight: bold;
  color: black;
}

#nav a.router-link-exact-active {
  color:black;
}

header {
  left: 0;
  top: 0;
  width: 100%;
  background-color: #85b3d1ff;
}

body {
  margin: 0%;
}

.knapp {
  background-color : #b3c7d6ff;
  padding : 10px;
  border-radius: 25px;

}
</style>
