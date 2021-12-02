<template>
  <fixed-header>
    <div class="navbar">
      Your Content
    </div>
  </fixed-header>
</template>

<script>
import FixedHeader from 'vue-fixed-header'

export default {
  components: {
    FixedHeader
  }
}
</script>

<style>
.navbar.vue-fixed-header--isFixed {
  position: fixed;
  left: 0;
  top: 0;
  width: 100%;
}
</style>