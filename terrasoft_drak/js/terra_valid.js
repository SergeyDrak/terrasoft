(function ($) {
  Drupal.behaviors.theming_workservic = {
    attach: function (context, settings) {
      $('#terra-form').validate({
        rules: {
          domain: {
            required: true,
            minlength: 3,
            maxlength: 10
          },
          login: {
            required: true,
            minlength: 3,
            maxlength: 10
          },
          city: {
            minlength: 3,
            maxlength: 10
          },
          phone: {
            minlength: 5,
            maxlength: 7,
            digits:1
          }
        }
      });
      $('.wrapper-terra .form-type-select .form-select').styler();

    }
  };
})(jQuery);

