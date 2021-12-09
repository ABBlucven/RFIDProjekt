<template>
  <div class="container">
    <router-link
      class="classCard"
      v-for="Class in classes"
      :key="Class"
      :to="`/${Class}`"
    >
      <p>
        {{ Class }}
      </p>
    </router-link>
  </div>
</template>

<script>
import { db } from '../db'

export default {

  data () {
    return {
      classes: ['190S', '1901', '1902', '1903', '200S', '2001', '2002', '2003', '210S', '2101', '2102', '2103']
    }
  },
  firebase: {
    documents: db.ref('students'),
  },
}
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