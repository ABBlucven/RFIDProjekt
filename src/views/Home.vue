<template>
  <div class="home">
    <h1>Närvarande elever</h1>
    <div class="container">
      <div
        class="studentCard"
        v-for="elev in elever"
        :key="elev"
      >
        <p class="name">{{elev}}</p>
        <p>9:32</p>
      </div>
    </div>
  </div>
</template>

<script>
// @ is an alias to /src
// import HelloWorld from '@/components/HelloWorld.vue'

export default {
  name: 'Home',
  components: {
    // HelloWorld
  },
  data () {
    return {
      elever: ['Linus', 'Jonathan', 'Lucas', 'Arta']
    }
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
