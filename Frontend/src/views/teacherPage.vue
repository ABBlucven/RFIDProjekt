<template>
  <div class="container">
    <!-- <ul>
      <li
        v-for="(value, key) in documents[0]"
        :key="value"
      >{{ key }}</li>
    </ul> -->

    <!-- {{Object.keys( documents ) }} -->
    <router-link
      class="classCard"
      v-for="(value, key) in documents[0]"
      :key="value + key"
      :to="`/${key}`"
    >
      <p>
        {{ key }}
      </p>
    </router-link>
  </div>
</template>

<script>
import { db } from "../db";

export default {
  data() {
    return {
      documents: [],
    };
  },

  firebase: {
    documents: db.ref("students"),
  },

  created: {},
};
</script>

<style>
.container {
  display: flex;
  flex-wrap: wrap;
  padding: 50px;
  justify-content: center;
  align-items: center;
  font-family: Arial, sans-serif;
}
.classCard {
  min-width: 200px;
  min-height: 100px;
  background-color: rgb(138, 211, 253);
  padding: 20px;
  margin: 30px;
  text-align: center;
  box-shadow: 5px 5px 20px grey;
  text-decoration: none;
  color: black;
  font-size: 50px;
  font-weight: bold;
}
</style>