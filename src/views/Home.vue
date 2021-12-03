<template>
  <div class="home">
    <h1>Närvarande elever</h1>
    <div class="container">
      <div
        class="studentCard"
        v-for="elev in documents"
        :key="elev"
      >
        <p class="name">{{elev["name"]}}</p>
        <p>{{getTime(elev["timestamp"])}}</p>
      </div>
    </div>
  </div>
</template>

<script>
// @ is an alias to /src
// import HelloWorld from '@/components/HelloWorld.vue'
import { db } from '../db'
export default {
  name: 'Home',
  components: {
    // HelloWorld
  },
  data () {
    return {
      elever: ['Linus', 'Jonathan', 'Lucas', 'Arta', 'Edvin'],
      documents: [],

    }
  },
   created: function() {

   },
   firebase: {
    documents: db.ref('students/190S'),
  },
  methods: {
  getTime(timestamp) {
    const Time = new Date(timestamp)
    const time = Time.getHours() + ":" + Time.getMinutes();
    return time
  },
  }
}
</script>

<style scoped>
.home {
  text-align: center;
}
.container {
  display: flex;
  justify-content: center;
}
.studentCard {
  width: 200px;
  height: 150px;
  background-color: cadetblue;
  padding: 20px;
  margin: 20px;
}
.name {
  font-size: 30px;
}
</style>
